#pragma once

#include<iostream>
#include<sstream>
#include<fstream>
#include<stdint.h>
#include<unordered_map>
#include<vector>
#include<variant>

namespace MyJSON
{
	/*----------JSON类定义----------*/
	enum JSONTYPE{Jerror = -1, Jinitial, Jobject, Jarray,
					Jstring, Jnumber, Jbool, Jnull};
	class JSON_value
	{
		JSONTYPE type = Jinitial;

	public:
		JSONTYPE Get_type(){return type;}

		virtual JSON_value* Parser(std::stringstream& ss);
		// static JSON_value* Parser(std::)
		JSON_value* Parser(std::ifstream& fs);

		virtual std::ostream& Print(std::ostream& os){os << "Error\n";return os;}

		JSON_value(JSONTYPE _type = Jinitial):type(_type){}
		virtual ~JSON_value(){}
	};

	class JSON_object: public JSON_value
	{
		std::unordered_map<std::string, JSON_value*> child;

	public:
		JSON_value* Parser(std::stringstream& ss) override;
		std::ostream& Print(std::ostream& os) override;

		// JSON_value& operator [] (std::string key){return *child[key];}
		int Get_size(){return child.size();}
		void Insert(std::string key, JSON_value* value){child.insert({key,value});}

		JSON_object():JSON_value(Jobject){}
		~JSON_object(){}//释放map？
	};

	class JSON_array: public JSON_value
	{
		std::vector<JSON_value*> child;

	public:
		JSON_value* Parser(std::stringstream& ss) override;
		std::ostream& Print(std::ostream& os) override;

		// JSON_value& operator [] (int index){return *child[index];}
		int Get_size(){return child.size();}
		//position in [0~size]
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

	extern std::string SyntaxError_Object;
	extern std::string SyntaxError_Array;
	extern std::string SyntaxError_String;
	extern std::string SyntaxError_Number;
	extern std::string SyntaxError_UnknownType;
	extern std::string Error_BrokenFile;
	extern std::string No_Error;
	class JSON_error: public JSON_value
	{
		std::string errorType;
		const int position;
		std::string Error_Code = "?";
	public:

		std::ostream& Print(std::ostream& os) override;

		JSON_error(std::stringstream& ss, int p = 0, std::string e = No_Error):JSON_value(Jerror),errorType(e),position(p)
		{
			ss.seekg(position);
			getline(ss, Error_Code);
		}
	};
	/*----------JSON类定义----------*/
}