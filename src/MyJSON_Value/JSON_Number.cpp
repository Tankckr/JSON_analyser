#include"JSON_Number.h"
#include"JSON_Error.h"

#include<regex>

namespace MyJSON
{
	std::variant<int64_t, double, std::string> JSON_Number::get_value()
	{
		if (out_of_range_)
			return value_string_;
		else if (value_type_)
			return value_double_;
		else
			return value_int_;
	}

	bool JSON_Number::set_value(std::string value)
	{
		std::smatch match;
		std::regex number(
			"^-?([0]|[1-9][0-9]*)(\\.[0-9]{1,})?([e|E][+|-]?[1-9][0-9]*)?");
		if (std::regex_match(value, match, number)) {
			std::string value = match.str();
		} else {
			std::cerr << "ErrorTpye_Number: Invalid number\n";
			return false;
		}
		///reset number
		value_type_ = false;
		out_of_range_ = false;
		value_int_ = 0;
		value_double_ = 0;
		value_string_ = "initial";

		for (int i = 0; i < value.size(); i++) {
			if (value[i] == '.' || value[i] == 'e' || value[i] == 'E') {
				value_type_ = true;
			}
		}
		if (value_type_) {
			try {
				value_double_ = std::stod(value);
			} catch (const std::out_of_range& e) {
				out_of_range_ = true;
			}
		} else {
			try {
				value_int_ = std::stoll(value);
			} catch (const std::out_of_range& e) {
				out_of_range_ = true;
			}
		}
		value_string_ = value;		//有没有越界都存一个string,print直接使用
		return true;
	}
	/*----------parser----------*/
	std::shared_ptr<JSON_Value> JSON_Number::parser(
			std::stringstream& ss,
			std::shared_ptr<JSON_Value> fa)
	{
		ignore_blank(ss);
		std::string ms = ss.str().substr(ss.tellg());
		std::smatch match;
		std::regex number(
			"^-?([0]|[1-9][0-9]*)(\\.[0-9]{1,})?([e|E][+|-]?[1-9][0-9]*)?");
		if (std::regex_search(ms, match, number)) {
			std::shared_ptr<JSON_Number> ret = std::make_shared<JSON_Number>();
			ret->set_father(fa);
			if (!ret->set_value(match.str())) {
				return std::make_shared<JSON_Error>(ss,
													ss.tellg(),
													syntax_error_number);
			}
			ss.ignore(match.str().size());
			return ret;
		} else {
			return std::make_shared<JSON_Error>(ss,
												ss.tellg(),
												syntax_error_number);
		}
	}
	/*----------print----------*/
	std::ostream& JSON_Number::print(std::ostream& os)
	{
		os << value_string_;
		return os;
	}
}