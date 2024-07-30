#include"SAJ.h"
#include<regex>

namespace SAJ
{
	bool SAJ_Parser::SAJ_null(std::stringstream& ss, SAJ_Processor& p)
	{
		ignore_blank(ss);
		std::string ms = ss.str().substr(ss.tellg());
		std::smatch match;
		std::regex N("^(null)");
		if (std::regex_search(ms, match, N)) {
			p.null();
			ss.ignore(4);
			return true;
		} else {
			std::string error_code;
			getline(ss, error_code);
			p.error(error_line, "Error: unknown value type");
			return false;
		}
	}
}