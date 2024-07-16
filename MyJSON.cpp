#include"MyJSON.h"
#include <regex>

namespace MyJSON
{
	// JSON_error GlobalError;

/*----------功能函数----------*/
	void IgnoreBlank(std::stringstream& ss)
	{
		while(ss.peek() > 0 && ss.peek() <= 32)
		{
			ss.ignore();
		}
	}
	
/*----------功能函数----------*/

/*----------类函数----------*/
/*-----解析函数-----*/
	/*---JSON_value---*/
	JSON_value* JSON_value::Parser(std::stringstream& ss)
	{
		//WARNING JSON_value的parser不会变更自身指针，如果在最外层处理的时候记得获取返回值
		IgnoreBlank(ss);
		char ch = ss.peek();
		if(ch == '{'){
			JSON_object* ret;
			return ret->Parser(ss);
		}
		if(ch == '['){
			JSON_array* ret;
			return ret->Parser(ss);
		}
		if(ch == '"'){
			JSON_string* ret;
			return ret->Parser(ss);
		}
		if(ch == '-' || (ch <= '9' && ch >= '0')){
			JSON_number* ret;
			return ret->Parser(ss);
		}
		if(ch == 't' || ch == 'f'){
			JSON_bool* ret;
			return ret->Parser(ss);
		}
		if(ch == 'n'){
			JSON_null*ret;
			return ret->Parser(ss);
		}
		//else
		return new JSON_error(JSON_error::ErrorType_UnknownType, ss.tellg());
	}
	/*---JSON_value---*/
	/*---JSON_object---*/
	JSON_value* JSON_object::Parser(std::stringstream& ss)
	{
		IgnoreBlank(ss);
		if (ss.peek() != '{'){
			return new JSON_error(JSON_error::ErrorType_Object, ss.tellg());
		}ss.ignore();
		IgnoreBlank(ss);
		if(ss.peek() == '}'){	//{}
			ss.ignore();
			return new JSON_object;
		}
		while (ss.peek() != EOF)
		{
			/*---"key"---*/
			JSON_string parserS;
			JSON_value* ErrorReporter;
			ErrorReporter = parserS.Parser(ss);
			if(ErrorReporter->Get_type() == Jerror){
				return ErrorReporter;
			}
			std::string key = parserS.Get_value();
			/*---"key"---*/
			/*---:---*/
			IgnoreBlank(ss);
			if(ss.peek() != ':'){
				return new JSON_error(JSON_error::ErrorType_Object, ss.tellg());
			}ss.ignore();
			/*---:---*/
			/*---value---*/
			JSON_value* parserV;
			parserV = parserV->Parser(ss);
			/*---value---*/
			Insert(key, parserV);	//Error也可以插进去，不至于一个error使得全部解析失败
			/*---next---*/
			IgnoreBlank(ss);
			if(ss.peek() == ',') continue;
			else if(ss.peek() == '}') return this;
			else return new JSON_error(JSON_error::ErrorType_Object, ss.tellg());
			/*---next---*/
		}//不完整的文件
		return new JSON_error(JSON_error::Error_BrokenFile, ss.tellg());
	}
	/*---JSON_object---*/
	/*---JSON_array---*/
	JSON_value* JSON_array::Parser(std::stringstream& ss)
	{
		IgnoreBlank(ss);
		if(ss.peek() != '['){
			return new JSON_error(JSON_error::ErrorType_Array, ss.tellg());
		}ss.ignore();
		IgnoreBlank(ss);
		if(ss.peek() == ']'){
			return new JSON_array;
		}
		while(ss.peek()!=EOF)
		{
			/*---value---*/
			JSON_value* parser;
			parser = parser->Parser(ss);
			/*---value---*/
			Insert(Get_size(), parser);
			/*---next---*/
			IgnoreBlank(ss);
			if(ss.peek() == ',') continue;
			else if(ss.peek() == ']') return this;
			else return new JSON_error(JSON_error::ErrorType_Array, ss.tellg());
			/*---next---*/
		}
		return new JSON_error(JSON_error::Error_BrokenFile, ss.tellg());
	}
	/*---JSON_array---*/
	/*---JSON_string---*/
	JSON_value* JSON_string::Parser(std::stringstream& ss)
	{
		IgnoreBlank(ss);
		std::string ms = ss.str().substr(ss.tellg());
		std::smatch match;
		std::regex pattern("^\"[^\"]*\"");
		if(std::regex_search(ms, match, pattern))
		{
			Set_value(match.str());
			ss.ignore(match.str().size());
			return this;
		}
		else return new JSON_error(JSON_error::ErrorType_String, ss.tellg());
	}
	/*---JSON_string---*/
	/*---JSON_number---*/
	JSON_value* JSON_number::Parser(std::stringstream& ss)
	{
		IgnoreBlank(ss);
		std::string ms = ss.str().substr(ss.tellg());
		std::smatch match;
		std::regex number("^-?([0]|[1-9][0-9]*)(.[0-9]{1,})?([e|E][+|-]?[1-9][0-9]*)?");
		if(std::regex_search(ms, match, number))
		{
			if(!Set_value(match.str())){
				return new JSON_error(JSON_error::ErrorType_Number, ss.tellg());
			}
			ss.ignore(match.str().size());
			return this;
		}
		else return new JSON_error(JSON_error::ErrorType_Number, ss.tellg());
	}

	bool JSON_number::Set_value(std::string value)
	{
		std::smatch match;
		std::regex number("^-?([0]|[1-9][0-9]*)(.[0-9]{1,})?([e|E][+|-]?[1-9][0-9]*)?");
		if(std::regex_match(value, match, number))
		{
			std::string value = match.str();
		}
		else
		{
			std::cerr << "ErrorTpye_Number: Invalid number\n";
			return false;
		}
		for (int i = 0; i < value.size(); i++)
		{
			if(value[i] == '.' || value[i] == 'e' || value[i] == 'E')
			{
				valueType = true;
			}
		}
		if(valueType)
		{
			try{
				valueDouble = std::stod(value);
			}catch (const std::out_of_range& e){
				outOfRange = true;
			}
		}
		else
		{
			try{
				valueInt = std::stoll(value);
			}catch (const std::out_of_range& e){
				outOfRange = true;
			}
		}
		valueLarge = value;		//有没有越界都存一个string,print直接使用
		return true;
	}
	/*---JSON_number---*/
	/*---JSON_bool---*/
	JSON_value* JSON_bool::Parser(std::stringstream& ss)
	{
		IgnoreBlank(ss);
		std::string ms = ss.str().substr(ss.tellg());
		std::smatch match;
		std::regex T("^(true)");
		std::regex F("^(false)");
		if (std::regex_search(ms, match, T))
		{
			value = true;
		}
		else if (std::regex_search(ms, match, F))
		{
			value = false;
		}
		else return new JSON_error(JSON_error::ErrorType_UnknownType, ss.tellg());
		return this;
	}
	/*---JSON_bool---*/
	/*---JSON_null---*/
	JSON_value* JSON_null::Parser(std::stringstream& ss)
	{
		IgnoreBlank(ss);
		std::string ms = ss.str().substr(ss.tellg());
		std::smatch match;
		std::regex N("^(null)");
		if (std::regex_search(ms, match, N))
		{
			return this;
		}else return new JSON_error(JSON_error::ErrorType_UnknownType, ss.tellg());
	}
	/*---JSON_null---*/
/*-----解析函数-----*/
/*-----打印函数-----*/
	/*---JSON_object---*/
	std::ostream& JSON_object::Print(std::ostream& os = std::cout)
	{
		;
	}
	/*---JSON_object---*/
	/*---JSON_array---*/
	std::ostream& JSON_array::Print(std::ostream& os = std::cout)
	{
		;
	}
	/*---JSON_array---*/
	/*---JSON_number---*/
	std::ostream& JSON_number::Print(std::ostream& os = std::cout)
	{
		os << valueLarge;
		return os;
	}
	std::variant<int64_t, double, std::string> JSON_number::Get_value()
	{
		if(outOfRange)
			return valueLarge;
		else if (valueType)
			return valueDouble;
		else
			return valueInt;
	}
	/*---JSON_number---*/
	/*---JSON_bool---*/
	std::ostream& JSON_bool::Print(std::ostream& os = std::cout)
	{
		if(value){
			os << "true";
		}
		else{
			os << "false";
		}
		return os;
	}
	/*---JSON_bool---*/
	/*---JSON_null---*/
	std::ostream& JSON_null::Print(std::ostream& os = std::cout)
	{
		os << "null";
		return os;
	}
	/*---JSON_null---*/

	/*-----打印函数-----*/

	/*----------类函数----------*/
}