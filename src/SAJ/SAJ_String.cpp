#include"SAJ.h"
#include<regex>

namespace SAJ
{
	bool SAJ_Parser::SAJ_string(std::stringstream& ss, SAJ_Processor& p)
	{
		ignore_blank(ss);
		std::string ms = ss.str().substr(ss.tellg());
		std::smatch match;
		std::regex pattern("^\"[^\"]*\"");
		if (std::regex_search(ms, match, pattern)) {
			p.string(match.str());
			ss.ignore(match.str().size());
			return true;
		} else {
			std::string error_code;
			getline(ss, error_code);
			p.error(error_line, error_code, "Error: string invalid");
			return false;
		}
}
}