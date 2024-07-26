#include"SAJ.h"
#include<regex>

namespace SAJ
{
	bool SAJ_Parser::SAJ_bool(std::stringstream& ss, SAJ_Processor& p)
	{
		ignore_blank(ss);
		std::string ms = ss.str().substr(ss.tellg());
		std::smatch match;
		std::regex T("^(true)");
		std::regex F("^(false)");
		if (std::regex_search(ms, match, T)) {
			p.boolean(true);
			ss.ignore(4);
			return true;
		} else if (std::regex_search(ms, match, F)) {
			p.boolean(false);
			ss.ignore(5);
			return true;
		} else {
			std::string error_code;
			getline(ss, error_code);
			p.error(error_line, error_code, "Error: unknown value type");
			return false;
		}
	}
}