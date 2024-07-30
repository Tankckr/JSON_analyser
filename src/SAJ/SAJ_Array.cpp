#include"SAJ.h"

namespace SAJ
{
	bool SAJ_Parser::SAJ_array(std::stringstream& ss, SAJ_Processor& p)
	{
		p.array_start();
		if (ss.peek() != '[') {
			p.error(error_line, "Error: array syntax, Expect: '['");
			return false;
		}ss.ignore();
		ignore_blank(ss);
		if (ss.peek() == ']') {
			ss.ignore();
			p.array_end();
			return true;
		}
		while (ss.peek() != EOF) {
			/*---value---*/
			if (!SAJ_value(ss, p)) {
				return false;
			}
			/*---next---*/
			ignore_blank(ss);
			if (ss.peek() == ',') {
				ss.ignore();
				continue;
			} else if (ss.peek() == ']') {
				ss.ignore();
				p.array_end();
				return true;
			} else {
				p.error(error_line, "Error: array syntax, Expect: ','");
				return false;
			}
		}
		p.error(error_line, "12345Error: Stream unexpectedly over");
		return false;
	}
}