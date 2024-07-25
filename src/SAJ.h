#pragma once
#include<iostream>
#include<sstream>
#include<stdint.h>
namespace MyJSON
{
	//处理器
	class SAJ_Processor
	{
	public:
		virtual void parse_start() = 0;
		virtual void parse_end() = 0;
		virtual void object_start() = 0;
		virtual void object_end() = 0;
		virtual void object_key(std::string) = 0;
		virtual void array_start() = 0;
		virtual void array_end() = 0;
		virtual void string(std::string) = 0;
		virtual void number_int(int64_t) = 0;
		virtual void number_double(double) = 0;
		virtual void number_out_of_range(std::string) = 0;
		virtual void boolean(bool) = 0;
		virtual void null() = 0;
		virtual void error(int error_line,
						   std::string last_token,
						   std::string error_info) = 0;
	};

	//解析器
	class SAJ_Parser
	{
		static bool SAJ_value(std::stringstream&, SAJ_Processor&);
		static bool SAJ_object(std::stringstream&, SAJ_Processor&);
		static bool SAJ_array(std::stringstream&, SAJ_Processor&);
		static bool SAJ_string(std::stringstream&, SAJ_Processor&);
		static bool SAJ_number(std::stringstream&, SAJ_Processor&);
		static bool SAJ_bool(std::stringstream&, SAJ_Processor&);
		static bool SAJ_null(std::stringstream&, SAJ_Processor&);

		friend void parse_to_SAJ(std::stringstream&, SAJ_Processor&);
	};
	void parse_to_SAJ(std::stringstream&, SAJ_Processor&);
}