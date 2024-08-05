#include"SAJ.h"

namespace SAJ
{
	thread_local int SAJ_Parser::error_line = 1;
	void SAJ_Parser::ignore_blank(std::istream& ss)
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
		p.parse_start();
		if (!SAJ_Parser::SAJ_value(is, p)) {
			std::cout << "Error!!!\n";
			return;
		}
		p.parse_end();
		std::cout << "SAJ success!\n";
	}
}