#pragma once
#include"JSON_Value.h"

namespace MyJSON
{
	class JSON_Parser
	{
		Parse_State state_;
	public:
		static std::shared_ptr<JSON_Value> val_parser(
				std::istream&,
				std::shared_ptr<JSON_Value> fa,
				Parse_State&);
		static std::shared_ptr<JSON_Value> obj_parser(
				std::istream&,
				std::shared_ptr<JSON_Value> fa,
				Parse_State&);
		static std::shared_ptr<JSON_Value> arr_parser(
				std::istream&,
				std::shared_ptr<JSON_Value> fa,
				Parse_State&);
		static std::shared_ptr<JSON_Value> str_parser(
				std::istream&,
				std::shared_ptr<JSON_Value> fa,
				Parse_State&);
		static std::shared_ptr<JSON_Value> num_parser(
				std::istream&,
				std::shared_ptr<JSON_Value> fa,
				Parse_State&);
		static std::shared_ptr<JSON_Value> boo_parser(
				std::istream&,
				std::shared_ptr<JSON_Value> fa,
				Parse_State&);
		static std::shared_ptr<JSON_Value> nul_parser(
				std::istream&,
				std::shared_ptr<JSON_Value> fa,
				Parse_State&);
		bool parse(std::istream& is, JSON_Value& val);

		bool get_state()
		{
			return state_.get_state();
		}
	};

	class Parse_State
	{
		bool state_ = true;	// Error:false
		std::string error_code_;

		int error_line_ = 1;
	public:
		void ignore_blank(std::istream& is);
		bool get_state()
		{
			return state_;
		}
		// Error
		void set_error(std::string ec)
		{
			state_ = false;
			error_code_ = ec;
		}
	};
}