#include"SAJ.h"
#include<regex>

namespace SAJ
{
	bool SAJ_Parser::SAJ_object(std::stringstream& ss, SAJ_Processor& p)
	{
		p.object_start();
		if (ss.peek() != '{') {
			p.error(error_line, "Error: object syntax, Expect:'{'");
			return false;
		}ss.ignore();
		ignore_blank(ss);
		if (ss.peek() == '}') {	//{}
			ss.ignore();
			p.object_end();
			return true;
		}
		while (ss.peek() != EOF) {
			ignore_blank(ss);
			/*---key---*/
			std::string ms = ss.str().substr(ss.tellg());
			std::smatch match;
			std::regex pattern("^\"[^\"]*\"");
			if (std::regex_search(ms, match, pattern)) {
				p.object_key(match.str());
				ss.ignore(match.str().size());
			} else {
				std::string error_code;
				getline(ss, error_code);
				p.error(error_line, "Error: object key invalid");
				return false;
			}
			/*---:---*/
			ignore_blank(ss);
			if (ss.peek() != ':') {
				p.error(error_line, "Error: object [key:value]pair, Expect: ':'");
				return false;
			}ss.ignore();
			/*---value---*/
			ignore_blank(ss);
			if (!SAJ_value(ss, p)) {
				return false;
			}
			/*---next---*/
			ignore_blank(ss);
			if (ss.peek() == ',') {
				ss.ignore();
				continue;
			} else if (ss.peek() == '}') {
				ss.ignore();
				p.object_end();
				return true;
			} else {
				p.error(error_line, "Error: object syntax, Expect: ','");
				return false;
			}
		}
		p.error(error_line, "objectError: Stream unexpectedly over");
		return false;
	}
}