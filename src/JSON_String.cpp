#include"JSON_String.h"
#include"JSON_Error.h"

#include<regex>

namespace MyJSON
{
	/*----------parser----------*/
	std::shared_ptr<JSON_Value> JSON_String::parser(std::stringstream& ss)
	{
		ignore_blank(ss);
		std::string ms = ss.str().substr(ss.tellg());
		std::smatch match;
		std::regex pattern("^\"[^\"]*\"");
		if (std::regex_search(ms, match, pattern)) {
			std::shared_ptr<JSON_String> ret = std::make_shared<JSON_String>();
			ret->set_value(match.str());
			set_value(match.str());//给object解析用
			ss.ignore(match.str().size());
			return ret;
		} else return std::make_shared<JSON_Error>(ss, ss.tellg(), syntax_error_string);
	}
	/*----------print----------*/
	std::ostream& JSON_String::print(std::ostream& os)
	{
		os << value_;
		return os;
	}
}