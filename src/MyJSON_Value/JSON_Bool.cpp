#include"JSON_Bool.h"
#include"JSON_Error.h"

#include<regex>

namespace MyJSON
{
	/*----------parser----------*/
	std::shared_ptr<JSON_Value> JSON_Bool::parser(std::stringstream& ss)
	{
		ignore_blank(ss);
		std::string ms = ss.str().substr(ss.tellg());
		std::smatch match;
		std::regex T("^(true)");
		std::regex F("^(false)");
		std::shared_ptr<JSON_Bool> ret = std::make_shared<JSON_Bool>();
		if (std::regex_search(ms, match, T)) {
			ret->set_value(true);
			ss.ignore(4);
		} else if (std::regex_search(ms, match, F)) {
			ret->set_value(false);
			ss.ignore(5);
		} else {
			return std::make_shared<JSON_Error>(ss,
												ss.tellg(),
												syntax_error_unknown_type);
		}
		return ret;
	}
	/*----------print----------*/
	std::ostream& JSON_Bool::print(std::ostream& os)
	{
		if (value_) {
			os << "true";
		} else {
			os << "false";
		}
		return os;
	}
}