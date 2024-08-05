#pragma once
#include<iostream>
#include<sstream>
#include<stdint.h>
#include<thread>
namespace SAJ
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
						   std::string error_info) = 0;
	};

	//解析器
	class SAJ_Parser
	{
		thread_local static int error_line;
		static void ignore_blank(std::istream& ss);
		
		static bool SAJ_value(std::istream&, SAJ_Processor&);
		static bool SAJ_object(std::istream&, SAJ_Processor&);
		static bool SAJ_array(std::istream&, SAJ_Processor&);
		static bool SAJ_string(std::istream&, SAJ_Processor&);
		static bool SAJ_number(std::istream&, SAJ_Processor&);
		static bool SAJ_bool(std::istream&, SAJ_Processor&);
		static bool SAJ_null(std::istream&, SAJ_Processor&);

		friend void parse_to_SAJ(std::istream&, SAJ_Processor&);
	};
	//可以把这个类参数弄成一个模板，静态在执行效率上面会有些许优势
	void parse_to_SAJ(std::istream&, SAJ_Processor&);

}