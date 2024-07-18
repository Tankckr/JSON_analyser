#include"MyJSON.h"
#include <regex>

namespace MyJSON
{
	// JSON_error GlobalError;

/*----------功能函数----------*/
	int ErrorLine = 1;

	void IgnoreBlank(std::stringstream& ss)
	{
		while(ss.peek() > 0 && ss.peek() <= 32)
		{
			if(ss.peek() == '\n')ErrorLine++;
			ss.ignore();
		}
	}
/*----------功能函数----------*/

/*----------类函数----------*/
/*-----解析函数-----*/
	/*---JSON_value---*/
	JSON_value* JSON_value::Parser(std::ifstream& fs)
	{
		std::stringstream ss;
		ss << fs.rdbuf();
		return Parser(ss);
	}
	JSON_value* JSON_value::Parser(std::stringstream& ss)
	{
		//WARNING JSON_value的parser不会变更自身指针，如果在最外层处理的时候记得获取返回值
		IgnoreBlank(ss);
		char ch = ss.peek();
		if(ch == '{'){
			JSON_object* ret = new JSON_object;
			return ret->Parser(ss);
		}
		if(ch == '['){
			JSON_array* ret = new JSON_array;
			return ret->Parser(ss);
		}
		if(ch == '"'){
			JSON_string* ret = new JSON_string;
			return ret->Parser(ss);
		}
		if(ch == '-' || (ch <= '9' && ch >= '0')){
			JSON_number* ret = new JSON_number;
			return ret->Parser(ss);
		}
		if(ch == 't' || ch == 'f'){
			JSON_bool* ret = new JSON_bool;
			return ret->Parser(ss);
		}
		if(ch == 'n'){
			JSON_null*ret = new JSON_null;
			return ret->Parser(ss);
		}
		//else
		return new JSON_error(ss, ss.tellg(), SyntaxError_UnknownType);
	}
	/*---JSON_value---*/
	/*---JSON_object---*/
	JSON_value* JSON_object::Parser(std::stringstream& ss)
	{
		IgnoreBlank(ss);
		if (ss.peek() != '{'){
			return new JSON_error(ss, ss.tellg(), SyntaxError_Object);
		}ss.ignore();
		IgnoreBlank(ss);
		if(ss.peek() == '}'){	//{}
			ss.ignore();
			return new JSON_object;
		}
		while (ss.peek() != EOF)
		{
			/*---"key"---*/
			JSON_string* parserS = new JSON_string;
			parserS->Parser(ss);
			if(parserS->Get_type() == Jerror){
				return parserS;
			}
			std::string key = parserS->Get_value();
			delete parserS;
			/*---"key"---*/
			/*---:---*/
			IgnoreBlank(ss);
			if(ss.peek() != ':'){
				int a = ss.tellg();
				return new JSON_error(ss, ss.tellg(), SyntaxError_Object);
			}ss.ignore();
			/*---:---*/
			/*---value---*/
			JSON_value* pV = new JSON_value;
			JSON_value* parserV = pV->Parser(ss);
			delete pV;
			/*---value---*/
			if(parserV->Get_type() == Jerror){
				return parserV;
			}
			Insert(key, parserV);
			/*---next---*/
			IgnoreBlank(ss);
			if(ss.peek() == ','){
				ss.ignore();
				continue;
			}
			else if(ss.peek() == '}'){
				ss.ignore();
				return this;
			}
			else return new JSON_error(ss, ss.tellg(), SyntaxError_Object);
			/*---next---*/
		}//不完整的文件
		return new JSON_error(ss, ss.tellg(), Error_BrokenFile);
	}
	/*---JSON_object---*/
	/*---JSON_array---*/
	JSON_value* JSON_array::Parser(std::stringstream& ss)
	{
		IgnoreBlank(ss);
		if(ss.peek() != '['){
			return new JSON_error(ss, ss.tellg(), SyntaxError_Array);
		}ss.ignore();
		IgnoreBlank(ss);
		if(ss.peek() == ']'){
			return new JSON_array;
		}
		while(ss.peek()!=EOF)
		{
			/*---value---*/
			JSON_value* p = new JSON_value;
			JSON_value* parser = p->Parser(ss);
			delete p;
			/*---value---*/
			if(parser->Get_type() == Jerror){
				return parser;
			}
			Insert(Get_size(), parser);
			/*---next---*/
			IgnoreBlank(ss);
			if(ss.peek() == ','){
				ss.ignore();
				continue;
			}
			else if(ss.peek() == ']')
			{
				ss.ignore();
				return this;
			}
			else return new JSON_error(ss, ss.tellg(), SyntaxError_Array);
			/*---next---*/
		}
		return new JSON_error(ss, ss.tellg(), Error_BrokenFile);
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
		else return new JSON_error(ss, ss.tellg(), SyntaxError_String);
	}
	/*---JSON_string---*/
	/*---JSON_number---*/
	JSON_value* JSON_number::Parser(std::stringstream& ss)
	{
		IgnoreBlank(ss);
		std::string ms = ss.str().substr(ss.tellg());
		std::smatch match;
		std::regex number("^-?([0]|[1-9][0-9]*)(\\.[0-9]{1,})?([e|E][+|-]?[1-9][0-9]*)?");
		if(std::regex_search(ms, match, number))
		{
			if(!Set_value(match.str())){
				return new JSON_error(ss, ss.tellg(), SyntaxError_Number);
			}
			ss.ignore(match.str().size());
			return this;
		}
		else return new JSON_error(ss, ss.tellg(), SyntaxError_Number);
	}

	bool JSON_number::Set_value(std::string value)
	{
		std::smatch match;
		std::regex number("^-?([0]|[1-9][0-9]*)(\\.[0-9]{1,})?([e|E][+|-]?[1-9][0-9]*)?");
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
			ss.ignore(4);
		}
		else if (std::regex_search(ms, match, F))
		{
			value = false;
			ss.ignore(5);
		}
		else return new JSON_error(ss, ss.tellg(), SyntaxError_UnknownType);
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
			ss.ignore(4);
			return this;
		}else return new JSON_error(ss, ss.tellg(), SyntaxError_UnknownType);
	}
	/*---JSON_null---*/
/*-----解析函数-----*/
/*-----打印函数-----*/
	//全局缩进
	int tab_deep = 0;
	std::ostream& operator<< (std::ostream& os, JSON_value* v)
	{
		if(v->Get_type() != Jinitial){
			return v->Print(os);
		}
		else{
			os << "Error, can not print void JSON\n";
			return os;
		}
	}
	/*---JSON_value---*/
	//initial直接报错，毕竟没有JSON_value的值
	/*---JSON_value---*/
	/*---JSON_object---*/
	std::ostream& JSON_object::Print(std::ostream& os)
	{
		if(Get_size() == 0){
			os << "{}";
			return os;
		}
		tab_deep++;
		os << "{\n";
		for(auto it = child.begin(); it != child.end(); ++it)
		{
			auto [k,v] = *it;
			for(int i = 0; i < tab_deep; i++){
				os<<'\t';
			}
			os << k << ':';
			if(v->Get_type() == Jobject || v->Get_type() == Jarray){
				os << v;
			}else{
				os << ' ' << v;
			}
			if(std::next(it) != child.end()){
				os << ',';
			}
			os << '\n';
		}
		tab_deep--;
		for(int i = 0; i < tab_deep; i++){
			os<<'\t';
		}
		os << '}';
		return os;
	}
	/*---JSON_object---*/
	/*---JSON_array---*/
	std::ostream& JSON_array::Print(std::ostream& os)
	{
		if(Get_size() == 0){
			os << "[]";
			return os;
		}
		tab_deep++;
		os << "[\n";
		int n = child.size();
		for(int i = 0; i < n; i++)
		{
			for(int i = 0; i < tab_deep; i++){
				os<<'\t';
			}
			os << child[i];
			if (i != n-1){
				os << ',';
			}
			os << '\n';
		}
		tab_deep--;
		for(int i = 0; i < tab_deep; i++){
			os<<'\t';
		}
		os << ']';
		return os;
	}
	/*---JSON_array---*/
	/*---JSON_string---*/
	std::ostream& JSON_string::Print(std::ostream& os)
	{
		os << value;
		return os;
	}
	/*---JSON_string---*/
	/*---JSON_number---*/
	std::ostream& JSON_number::Print(std::ostream& os)
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
	std::ostream& JSON_bool::Print(std::ostream& os)
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
	std::ostream& JSON_null::Print(std::ostream& os)
	{
		os << "null";
		return os;
	}
	/*---JSON_null---*/
	/*---JSON_error---*/
	std::ostream& JSON_error::Print(std::ostream& os)
	{
		os << errorType << "\nin line " << ErrorLine << '\n';
		os << "->" << Error_Code << '\n';
		return os;
	}
	/*Errors*/
	std::string SyntaxError_Object = "TypeError: The object struct is not valid.";
	std::string SyntaxError_Array = "TypeError: The array struct is not valid.";
	std::string SyntaxError_String = "TypeError: The string struct is not valid, maybe omit '\"'?";
	std::string SyntaxError_Number = "TypeError: The number is not valid, maybe some char in it?";
	std::string SyntaxError_UnknownType = "TypeError: Unknown Value Type, please check your spelling.";
	std::string Error_BrokenFile = "FileError: Stream unexpectedly over.";
	std::string No_Error = "NoError?";
	// std::string SyntaxError_Object = "SyntaxError: object";
	// std::string SyntaxError_Array = "SyntaxError: array";
	// std::string SyntaxError_String = "SyntaxError: string";
	// std::string SyntaxError_Number = "SyntaxError: number";
	// std::string SyntaxError_UnknownType = "TypeError: Unknown Type";
	// std::string Error_BrokenFile = "FileError: Stream unexpectedly over.";
	// std::string No_Error = "NoError?";
	/*---JSON_error---*/
	/*-----打印函数-----*/

	/*----------类函数----------*/
}