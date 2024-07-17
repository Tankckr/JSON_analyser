#pragma once

#include<iostream>
#include<sstream>
#include<stdint.h>
#include<unordered_map>
#include<vector>
#include<variant>

namespace MyJSON
{
	/*----------类定义----------*/
	enum JSONTYPE{Jerror = -1, Jinitial, Jobject, Jarray,
					Jstring, Jnumber, Jbool, Jnull};
	class JSON_value
	{
		JSONTYPE type = Jinitial;

	public:
		JSONTYPE Get_type(){return type;}

		virtual JSON_value* Parser(std::stringstream& ss);
		virtual std::ostream& Print(std::ostream& os);
		//std::ostream& operator << (std::ostream& os, const JSON_value* v);
		JSON_value(JSONTYPE _type = Jinitial):type(_type){}
		virtual ~JSON_value(){}
	};

	class JSON_object: public JSON_value
	{
		std::unordered_map<std::string, JSON_value*> child;

	public:
		JSON_value* Parser(std::stringstream& ss) override;
		std::ostream& Print(std::ostream& os) override;

		JSON_value& operator [] (std::string key){return *child[key];}
		int Get_size(){return child.size();}
		void Insert(std::string key, JSON_value* value){child[key] = value;}

		JSON_object():JSON_value(Jobject){}
		~JSON_object(){}//释放map？
	};

	class JSON_array: public JSON_value
	{
		std::vector<JSON_value*> child;

	public:
		JSON_value* Parser(std::stringstream& ss) override;
		std::ostream& Print(std::ostream& os) override;

		JSON_value& operator [] (int index);		//index
		int Get_size(){return child.size();}		//nums of child
		//position in (0~size)
		void Insert(int pos, JSON_value* n){child.insert(child.begin()+pos, n);}

		JSON_array():JSON_value(Jarray){}
		~JSON_array(){}//释放vector？
	};

	class JSON_string: public JSON_value
	{
		std::string value = "";

	public:
		JSON_value* Parser(std::stringstream& ss) override;
		std::ostream& Print(std::ostream& os) override;

		std::string Get_value(){return value;}
		void Set_value(std::string _v){value = _v;}

		JSON_string():JSON_value(Jstring){}
		~JSON_string(){}
	};

	class JSON_number: public JSON_value
	{
		int64_t valueInt = 0;
		double valueDouble = 0;
		std::string valueLarge = "initial";

		bool valueType = false;	//false: Int, true: double
		bool outOfRange = false;
	public:
		JSON_value* Parser(std::stringstream& ss) override;
		std::ostream& Print(std::ostream& os) override;

		std::variant<int64_t, double, std::string> Get_value();
		std::string Get_value_string(){return valueLarge;}
		std::string Get_value_type(){return outOfRange?"string":(valueType?"double":"int64");}

		bool Set_value(std::string _v);

		JSON_number():JSON_value(Jnumber){}
		~JSON_number(){}
	};

	class JSON_bool: public JSON_value
	{
		bool value = false;

	public:
		JSON_value* Parser(std::stringstream& ss) override;
		std::ostream& Print(std::ostream& os) override;

		bool Get_value(){return value;}
		void Set_value(bool _v){value = _v;}

		JSON_bool():JSON_value(Jbool){}
		~JSON_bool(){}
	};

	class JSON_null: public JSON_value
	{
	public:
		JSON_value* Parser(std::stringstream& ss) override;
		std::ostream& Print(std::ostream& os) override;

		JSON_null():JSON_value(Jnull){}
		~JSON_null(){}
	};

	/*Errors*/
	std::string ErrorType_Object =		"TypeError: The object struct is not valid.";
	std::string ErrorType_Array =		"TypeError: The array struct is not valid.";
	std::string ErrorType_String =		"TypeError: The string struct is not valid, maybe omit '\"'?";
	std::string ErrorType_Number =		"TypeError: The number is not valid, maybe some char in it?";
	std::string ErrorType_UnknownType =	"TypeError: Unknown Value Type, please check your spelling.";
	std::string Error_BrokenFile = "FileError: Stream unexpectedly over.";
	std::string No_Error = "";

	class JSON_error: public JSON_value
	{
	public:
		// enum ERRORTYPE
		// {
		// 	ErrorType_Object,		//"TypeError: The object struct is not valid."
		// 	ErrorType_Array,		//"TypeError: The array struct is not valid."
		// 	ErrorType_String,		//"TypeError: The string struct is not valid, maybe omit '\"'?"
		// 	ErrorType_Number,		//"TypeError: The number is not valid, maybe some char in it?"
		// 	ErrorType_UnknownType,	//"TypeError: Unknown Value Type, please check your spelling."
			
		// 	Error_BrokenFile,		//"FileError: Stream unexpectedly over."
		// 	No_Error,
		// };
		std::ostream& Print(std::ostream& os) override;

		JSON_error(std::string e = No_Error, int p = 0):JSON_value(Jerror),type(e),position(p)
		{
			std::vector<std::string> ErrorList;
			ErrorList.push_back("TypeError: The object struct is not valid.");
			ErrorList.push_back("TypeError: The array struct is not valid.");
			ErrorList.push_back("TypeError: The string struct is not valid, maybe omit '\"'.");
			ErrorList.push_back("TypeError: The number is not valid, maybe some char in it?");
			ErrorList.push_back("TypeError: Unknown Value Type, please check your spelling.");
			
			ErrorList.push_back("FileError: Stream unexpectedly over.");
			ErrorList.push_back("NoError: It means no error, but if you see this, sth went wrong!");
		}
	private:
		std::string type;
		int position;
	};

	/*----------类定义----------*/
}