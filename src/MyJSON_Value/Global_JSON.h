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

	class JSON_Parser;
	class Parse_State;
	class JSON_Printer;
	class Print_State;

	/*----------报错类型声明----------*/
	std::string type_string(JSON_Type& t);
}