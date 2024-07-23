#include"JSON_NULL.h"
#include"JSON_Error.h"
#include<regex>

namespace MyJSON
{
	/*----------parser----------*/
	std::shared_ptr<JSON_Value> JSON_NULL::parser(std::stringstream& ss)
	{
		ignore_blank(ss);
		std::string ms = ss.str().substr(ss.tellg());
		std::smatch match;
		std::regex N("^(null)");
		if (std::regex_search(ms, match, N)) {
			std::shared_ptr<JSON_NULL> ret = std::make_shared<JSON_NULL>();
			ss.ignore(4);
			return ret;
		} else return std::make_shared<JSON_Error>(ss, ss.tellg(), syntax_error_unknown_type);
	}
	/*----------print----------*/
	std::ostream& JSON_NULL::print(std::ostream& os)
	{
		os << "null";
		return os;
	}
}
