#pragma once
#include"JSON_Value.h"

namespace MyJSON
{
	class JSON_Number: public JSON_Value
	{
		int64_t value_int_ = 0;
		double value_double_ = 0;
		std::string value_string_ = "initial";

		bool value_type_ = false;	//false: Int, true: double
		bool out_of_range_ = false;
	public:
		std::shared_ptr<JSON_Value> parser(std::stringstream& ss) override;
		std::ostream& print(std::ostream& os) override;

		std::string get_value_type()
		{
			return out_of_range_ ? "string"
				   : value_type_ ? "double"
				   : "int64";
		}
		std::string get_value_string()
		{
			return value_string_;
		}
		std::variant<int64_t, double, std::string> get_value();

		bool set_value(std::string _v);

		JSON_Number():JSON_Value(JNUMBER) {}
		~JSON_Number() {}
	};
}