#include"SAJ.h"

namespace SAJ
{
	int error_line = 1;
	void SAJ_Parser::ignore_blank(std::stringstream& ss)
	{
		while (ss.peek() > 0 && ss.peek() <= 32) {
			if (ss.peek() == '\n') {
				error_line++;
			}
			ss.ignore();
		}
	}
	void parse_to_SAJ(std::stringstream& ss, SAJ_Processor& p)
	{
		p.parse_start();
		if(!SAJ_Parser::SAJ_value(ss, p)) {
			return;
		}
		p.parse_end();
	}
}