#pragma once
#include"JSON_Value.h"

namespace MyJSON
{
	class JSON_String: public JSON_Value
	{
		std::string value_ = "";
	public:
		// std::shared_ptr<JSON_Value> parser(
		// 	std::istream& ss,
		// 	std::shared_ptr<JSON_Value> fa) override;
		// std::ostream& print(std::ostream& os) override;

		std::string get_value()
		{
			return value_;
		}
		void set_value(std::string _v)
		{
			value_ = _v;
		}

		JSON_String():JSON_Value(JSTRING) {}
		virtual ~JSON_String() {}
	};
}