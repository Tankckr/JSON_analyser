#include"SAJ.h"

namespace SAJ
{
	bool SAJ_Parser::SAJ_bool(std::istream& ss, SAJ_Processor& p)
	{
		ignore_blank(ss);
		if (ss.peek() == 't') {
			ss.ignore();
			if (ss.peek() == 'r') {
				ss.ignore();
				if (ss.peek() == 'u') {
					ss.ignore();
					if (ss.peek() == 'e') {
						ss.ignore();
						p.boolean(true);
						return true;
					}
				}
			}
		} else if (ss.peek() == 'f') {
			ss.ignore();
			if (ss.peek() == 'a') {
				ss.ignore();
				if (ss.peek() == 'l') {
					ss.ignore();
					if (ss.peek() == 's') {
						ss.ignore();
						if (ss.peek() == 'e') {
							ss.ignore();
							p.boolean(false);
							return true;
						}
					}
				}
			}
		}
		p.error(error_line, "Error: unknown value type");
		return false;
	}
}