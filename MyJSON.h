#pragma once

#include<iostream>
#include<sstream>
#include<unordered_map>
#include<vector>

namespace MyJSON
{
	/*----------类定义----------*/
	enum JSONTYPE{Jinitial, Jobject, Jarray,
					Jstring, Jnumber, Jbool, Jnull};
	class JSON_value
	{
		JSON_value* left = nullptr;
		JSON_value* right = nullptr;
		JSONTYPE type = Jinitial;

	public:
		JSONTYPE Get_type(){return type;}

		JSON_value* Get_left(){return left;}
		JSON_value* Get_right(){return right;}

		void Set_left(JSON_value* p){left = p;}
		void Set_right(JSON_value* p){right = p;}

		virtual JSON_value* Parser(std::stringstream& ss);
		virtual std::ostream& Print(std::stringstream& ss);

		JSON_value(JSONTYPE _type = Jinitial):type(_type){}
		virtual ~JSON_value(){}
	};

	class JSON_object: public JSON_value
	{
		std::unordered_map<std::string, JSON_value*> child;

	public:
		JSON_value* Parser(std::stringstream& ss) override;
		std::ostream& Print(std::stringstream& ss) override;

		JSON_value& operator [] (std::string key);	//index
		int Get_size(){return child.size();}		//nums of child
		void Insert(JSON_value* n);					//insert

		JSON_object():JSON_value(Jobject){}
	};

	class JSON_array: public JSON_value
	{
		std::vector<JSON_value*> child;

	public:
		JSON_value* Parser(std::stringstream& ss) override;
		std::ostream& Print(std::stringstream& ss) override;

		JSON_value& operator [] (int index);		//index
		int Get_size(){return child.size();}		//nums of child
		void Insert_to(int pos, JSON_value* n);		//insert

		JSON_array():JSON_value(Jarray){}
	};

	class JSON_string: public JSON_value
	{
		std::string value;

	public:
		JSON_value* Parser(std::stringstream& ss) override;
		std::ostream& Print(std::stringstream& ss) override;

		std::string Get_value(){return value;}
		void Set_value(std::string _v){value = _v;}

		JSON_string():JSON_value(Jstring){}
	};

	class JSON_number: public JSON_value
	{
		int valueInt = 0;
		int valueDouble = 0;
		bool valueType = false;	//false: Int, true: double

	public:
		JSON_value* Parser(std::stringstream& ss) override;
		std::ostream& Print(std::stringstream& ss) override;

		int Get_value_int(){return valueInt;}
		double Get_value_double(){return valueDouble;}
		bool Get_value_type(){return valueType;}
		void Set_value(std::string _v);

		JSON_number():JSON_value(Jnumber){}
	};

	class JSON_bool: public JSON_value
	{
		bool value = false;

	public:
		JSON_value* Parser(std::stringstream& ss) override;
		std::ostream& Print(std::stringstream& ss) override;

		bool Get_value(){return value;}
		void Set_value(bool _v){value = _v;}

		JSON_bool():JSON_value(Jbool){}
	};

	class JSON_null: public JSON_value
	{
	public:
		JSON_value* Parser(std::stringstream& ss) override;
		std::ostream& Print(std::stringstream& ss) override;

		JSON_null():JSON_value(Jnull){}
	};

	class JSON_error
	{
	public:
		enum ERRORTYPE
		{
			E_No_Error,
			E_Error_Type,
			E_File_Cannot_Open,
		};
		const std::string Error_Type = "the first type of error";
		const std::string ERROR2 = "......";

		static void ERROR(ERRORTYPE e, std::ostream& os = std::cout);
	};

	/*----------类定义----------*/
}