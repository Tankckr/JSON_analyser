#pragma once
#include<iostream>
#include<memory>

namespace MyJSON
{
	/*----------JSON数据类型----------*/
	enum JSON_Type
	{
		JINITIAL,
		JOBJECT,
		JARRAY,
		JSTRING,
		JNUMBER,
		JBOOL,
		JNULL,
	};
	/*----------类前置声明----------*/
	class JSON_Value;
	class JSON_Object;
	class JSON_Array;
	class JSON_String;
	class JSON_Number;
	class JSON_Bool;
	class JSON_NULL;

	/*----------报错类型声明----------*/
	// extern std::string syntax_error_object;
	// extern std::string syntax_error_array;
	// extern std::string syntax_error_string;
	// extern std::string syntax_error_number;
	// extern std::string syntax_error_unknown_type;
	// extern std::string error_broken_file;
	// extern std::string no_error;

	/*----------非成员函数声明----------*/
	// std::ostream& operator<< (std::ostream& os,
	// 						  std::shared_ptr<JSON_Value>& v);
	std::string type_string(JSON_Type& t);
}