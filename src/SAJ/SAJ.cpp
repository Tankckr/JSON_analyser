#include"SAJ.h"

namespace SAJ
{
	int SAJ_Parser::error_line = 1;
	void SAJ_Parser::ignore_blank(std::stringstream& ss)
	{
		while (ss.peek() > 0 && ss.peek() <= 32) {
			if (ss.peek() == '\n') {
				error_line++;
			}
			ss.ignore();
		}
	}
	void parse_to_SAJ(std::istream& is, SAJ_Processor& p)
	{
		std::stringstream ss;
		ss << is.rdbuf();
		p.parse_start();
		if (!SAJ_Parser::SAJ_value(ss, p)) {
			std::cout << "Error!!!\n";
			return;
		}
		p.parse_end();
	}
}