#include"SAJ.h"

namespace SAJ
{
	bool SAJ_Parser::SAJ_null(std::istream& ss, SAJ_Processor& p)
	{
		ignore_blank(ss);
		if (ss.peek() == 'n') {
			ss.ignore();
			if (ss.peek() == 'u') {
				ss.ignore();
				if (ss.peek() == 'l') {
					ss.ignore();
					if (ss.peek() == 'l') {
						ss.ignore();
						p.null();
						return true;
					}
				}
			}
		}
		p.error(error_line, "Error: unknowned value type");
		return false;
	}
}