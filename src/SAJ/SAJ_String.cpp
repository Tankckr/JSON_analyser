#include"SAJ.h"

namespace SAJ
{
	bool SAJ_Parser::SAJ_string(std::istream& ss, SAJ_Processor& p)
	{
		ignore_blank(ss);
		if (ss.peek() == '"') {
			ss.ignore();
			std::string str = "";
			while (ss.peek() != '"' && ss.peek() != EOF)
			{
				str += char(ss.peek());
				ss.ignore();
			}
			if (ss.peek() == '"') {
				ss.ignore();
				p.string(str);
				return true;
			} else {
				p.error(error_line, "Error: stream ended unexpectedly");
				return false;
			}
		} else {
			p.error(error_line, "Error: string syntax, Expect: '\"'");
			return false;
		}
	}
}