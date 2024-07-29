#include"Global_JSON.h"
#include"JSON_Value.h"
#include <regex>

namespace MyJSON
{
	/*----------非成员函数定义----------*/
	void ignore_blank(std::stringstream& ss)
	{
		while (ss.peek() > 0 && ss.peek() <= 32) {
			if (ss.peek() == '\n') {
				error_line++;
			}
			ss.ignore();
		}
	}
	std::ostream& operator<< (std::ostream& os, std::shared_ptr<JSON_Value>& v)
	{
		if (v->get_type() != JINITIAL) {
			return v->print(os);
		} else {
			os << "Error, can not print void JSON\n";
			return os;
		}
	}
	std::string type_string(JSON_Type& t)
	{
		switch (t) {
		case JERROR:
			return "JERROR";
		case JINITIAL:
			return "JINITIAL";
		case JOBJECT:
			return "JOBJECT";
		case JARRAY:
			return "JARRAY";
		case JSTRING:
			return "JSTRING";
		case JNUMBER:
			return "JNUMBER";
		case JBOOL:
			return "JBOOL";
		case JNULL:
			return "JNULL";
		default:
			return "UNKNOWN";
		}
	}

	/*----------报错类型定义----------*/
	std::string syntax_error_object = "TypeError: "
									  "The object struct is not valid.";
	std::string syntax_error_array = "TypeError: "
									 "The array struct is not valid.";
	std::string syntax_error_string = "TypeError: "
									  "The string struct is not valid, "
									  "maybe omit '\"'?";
	std::string syntax_error_number = "TypeError: "
									  "The number is not valid, "
									  "maybe some char in it?";
	std::string syntax_error_unknown_type = "TypeError: "
											"Unknown Value Type, "
											"please check your spelling.";
	std::string error_broken_file = "FileError: Stream unexpectedly over.";
	std::string no_error = "NoError?";

	/*----------全局变量初始化----------*/
	int tab_deep = 0;
	int error_line = 1;
}