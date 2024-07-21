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
	std::shared_ptr<JSON_value> JSON_value::Parser(std::ifstream& fs)
	{
		std::stringstream ss;
		ss << fs.rdbuf();
		return Parser(ss);
	}
	std::shared_ptr<JSON_value> JSON_value::Parser(std::stringstream& ss)
	{
		//WARNING JSON_value的parser不会变更自身指针，如果在最外层处理的时候记得获取返回值
		IgnoreBlank(ss);
		char ch = ss.peek();
		if(ch == '{'){
			std::shared_ptr<JSON_object> ret = std::make_shared<JSON_object>();
			return ret->Parser(ss);
		}
		if(ch == '['){
			std::shared_ptr<JSON_array> ret = std::make_shared<JSON_array>();
			return ret->Parser(ss);
		}
		if(ch == '"'){
			std::shared_ptr<JSON_string> ret = std::make_shared<JSON_string>();
			return ret->Parser(ss);
		}
		if(ch == '-' || (ch <= '9' && ch >= '0')){
			std::shared_ptr<JSON_number> ret = std::make_shared<JSON_number>();
			return ret->Parser(ss);
		}
		if(ch == 't' || ch == 'f'){
			std::shared_ptr<JSON_bool> ret = std::make_shared<JSON_bool>();
			return ret->Parser(ss);
		}
		if(ch == 'n'){
			std::shared_ptr<JSON_null> ret = std::make_shared<JSON_null>();
			return ret->Parser(ss);
		}
		//else
		return std::make_shared<JSON_error>(ss, ss.tellg(), SyntaxError_UnknownType);
	}
	/*---JSON_value---*/
	/*---JSON_object---*/
	std::shared_ptr<JSON_value> JSON_object::Parser(std::stringstream& ss)
	{
		IgnoreBlank(ss);
		if (ss.peek() != '{'){
			return std::make_shared<JSON_error>(ss, ss.tellg(), SyntaxError_Object);
		}ss.ignore();
		IgnoreBlank(ss);
		if(ss.peek() == '}'){	//{}
			ss.ignore();
			return std::make_shared<JSON_object>();
		}
		while (ss.peek() != EOF)
		{
			/*---"key"---*/
			std::shared_ptr<JSON_string> parserS = std::make_shared<JSON_string>();
			parserS->Parser(ss);
			if(parserS->Get_type() == Jerror){
				return parserS;
			}
			std::string key = parserS->Get_value();
			/*---"key"---*/
			/*---:---*/
			IgnoreBlank(ss);
			if(ss.peek() != ':'){
				int a = ss.tellg();
				return std::make_shared<JSON_error>(ss, ss.tellg(), SyntaxError_Object);
			}ss.ignore();
			/*---:---*/
			/*---value---*/
			std::shared_ptr<JSON_value> pV = std::make_shared<JSON_value>();
			pV = pV->Parser(ss);
			/*---value---*/
			if(pV->Get_type() == Jerror){
				return pV;
			}
			Insert(key, pV);
			/*---next---*/
			IgnoreBlank(ss);
			if(ss.peek() == ','){
				ss.ignore();
				continue;
			}
			else if(ss.peek() == '}'){
				ss.ignore();
				return std::shared_ptr<JSON_object>(this);
			}
			else return std::make_shared<JSON_error>(ss, ss.tellg(), SyntaxError_Object);
			/*---next---*/
		}//不完整的文件
		return std::make_shared<JSON_error>(ss, ss.tellg(), Error_BrokenFile);
	}
	/*---JSON_object---*/
	/*---JSON_array---*/
	std::shared_ptr<JSON_value> JSON_array::Parser(std::stringstream& ss)
	{
		IgnoreBlank(ss);
		if(ss.peek() != '['){
			return std::make_shared<JSON_error>(ss, ss.tellg(), SyntaxError_Array);
		}ss.ignore();
		IgnoreBlank(ss);
		if(ss.peek() == ']'){
			return std::make_shared<JSON_array>();
		}
		while(ss.peek()!=EOF)
		{
			/*---value---*/
			std::shared_ptr<JSON_value> p = std::make_shared<JSON_value>();
			p = p->Parser(ss);
			/*---value---*/
			if(p->Get_type() == Jerror){
				return p;
			}
			Insert(Get_size(), p);
			/*---next---*/
			IgnoreBlank(ss);
			if(ss.peek() == ','){
				ss.ignore();
				continue;
			}
			else if(ss.peek() == ']')
			{
				ss.ignore();
				return std::shared_ptr<JSON_array>(this);
			}
			else return std::make_shared<JSON_error>(ss, ss.tellg(), SyntaxError_Array);
			/*---next---*/
		}
		return std::make_shared<JSON_error>(ss, ss.tellg(), Error_BrokenFile);
	}
	/*---JSON_array---*/
	/*---JSON_string---*/
	std::shared_ptr<JSON_value> JSON_string::Parser(std::stringstream& ss)
	{
		IgnoreBlank(ss);
		std::string ms = ss.str().substr(ss.tellg());
		std::smatch match;
		std::regex pattern("^\"[^\"]*\"");
		if(std::regex_search(ms, match, pattern))
		{
			Set_value(match.str());
			ss.ignore(match.str().size());
			return std::shared_ptr<JSON_string>(this);
		}
		else return std::make_shared<JSON_error>(ss, ss.tellg(), SyntaxError_String);
	}
	/*---JSON_string---*/
	/*---JSON_number---*/
	std::shared_ptr<JSON_value> JSON_number::Parser(std::stringstream& ss)
	{
		IgnoreBlank(ss);
		std::string ms = ss.str().substr(ss.tellg());
		std::smatch match;
		std::regex number("^-?([0]|[1-9][0-9]*)(\\.[0-9]{1,})?([e|E][+|-]?[1-9][0-9]*)?");
		if(std::regex_search(ms, match, number))
		{
			if(!Set_value(match.str())){
				return std::make_shared<JSON_error>(ss, ss.tellg(), SyntaxError_Number);
			}
			ss.ignore(match.str().size());
			return std::shared_ptr<JSON_number>(this);
		}
		else return std::make_shared<JSON_error>(ss, ss.tellg(), SyntaxError_Number);
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
	std::shared_ptr<JSON_value> JSON_bool::Parser(std::stringstream& ss)
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
		else return std::make_shared<JSON_error>(ss, ss.tellg(), SyntaxError_UnknownType);
		return std::shared_ptr<JSON_bool>(this);
	}
	/*---JSON_bool---*/
	/*---JSON_null---*/
	std::shared_ptr<JSON_value> JSON_null::Parser(std::stringstream& ss)
	{
		IgnoreBlank(ss);
		std::string ms = ss.str().substr(ss.tellg());
		std::smatch match;
		std::regex N("^(null)");
		if (std::regex_search(ms, match, N))
		{
			ss.ignore(4);
			return std::shared_ptr<JSON_null>(this);
		}else return std::make_shared<JSON_error>(ss, ss.tellg(), SyntaxError_UnknownType);
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