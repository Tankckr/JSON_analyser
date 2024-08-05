#include"SAJ.h"

namespace SAJ
{
	bool SAJ_Parser::SAJ_object(std::istream& ss, SAJ_Processor& p)
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
					p.object_key(str);
				} else {
					p.error(error_line, "Error: stream ended unexpectedly");
					return false;
				}
			} else {
				p.error(error_line, "Error: object key syntax, Expect: '\"'");
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