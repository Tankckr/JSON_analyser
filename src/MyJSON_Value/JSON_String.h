#pragma once
#include"JSON_Value.h"

namespace MyJSON
{
	class JSON_String: public JSON_Value
	{
		std::string value_ = "";
		/// @brief 在解析器中调用的设置值（json格式的string带""，为了方便使用，set不用加\"）
		/// @param string _v 
		void parser_set_value(std::string _v)
		{
			value_ = _v;
		}
	public:
		std::shared_ptr<JSON_Value> parser(
			std::stringstream& ss,
			std::shared_ptr<JSON_Value> fa) override;
		std::ostream& print(std::ostream& os) override;

		std::string get_value()
		{
			return value_;
		}
		void set_value(std::string _v)
		{
			value_ = '"' + _v + '"';
		}

		JSON_String():JSON_Value(JSTRING) {}
		~JSON_String() {}
	};
}