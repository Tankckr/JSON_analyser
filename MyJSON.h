#pragma once

#include<iostream>
#include<sstream>
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
		// JSON_value* left = nullptr;
		// JSON_value* right = nullptr;
		JSONTYPE type = Jinitial;

	public:
		JSONTYPE Get_type(){return type;}

		// JSON_value* Get_left(){return left;}
		// JSON_value* Get_right(){return right;}

		// void Set_left(JSON_value* p){left = p;}
		// void Set_right(JSON_value* p){right = p;}

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
		std::ostream& Print(std::stringstream& ss) override;

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
		std::ostream& Print(std::stringstream& ss) override;

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
		std::ostream& Print(std::stringstream& ss) override;

		// int Get_value_int(){return valueInt;}
		// double Get_value_double(){return valueDouble;}
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
		std::ostream& Print(std::stringstream& ss) override;

		bool Get_value(){return value;}
		void Set_value(bool _v){value = _v;}

		JSON_bool():JSON_value(Jbool){}
		~JSON_bool(){}
	};

	class JSON_null: public JSON_value
	{
	public:
		JSON_value* Parser(std::stringstream& ss) override;
		std::ostream& Print(std::stringstream& ss) override;

		JSON_null():JSON_value(Jnull){}
		~JSON_null(){}
	};

	class JSON_error: public JSON_value
	{
		std::vector<std::string> ErrorList;
		
		std::string File_Error = "File_Error:Can not open the JSON file or Empty file.";
		const std::string Error_Type = "the first type of error";
		const std::string ERROR2 = "......";

	public:
		enum ERRORTYPE
		{
			ErrorType_Object,
			ErrorType_Array,
			ErrorType_String,
			ErrorType_Number,
			ErrorType_Bool,
			ErrorType_UnknownType,

			Error_ValueOutOfRange,
			Error_BrokenFile,

			E_No_Error,
			E_File_Error,
			E_Error_Type,
		};
		JSON_error(ERRORTYPE e = E_No_Error, int p = 0):JSON_value(Jerror),type(e),position(p){}
	private:
		ERRORTYPE type = E_No_Error;
		int position;
	};

	/*----------类定义----------*/
}