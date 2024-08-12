#include"SAJ.h"

namespace SAJ
{
	bool SAJ_Parser::SAJ_value(std::istream& ss, SAJ_Processor& p)
	{
		ignore_blank(ss);
		char ch = ss.peek();
		if (ch == '{') {
			return SAJ_object(ss, p);
		}
		if (ch == '[') {
			return SAJ_array(ss, p);
		}
		if (ch == '"') {
			return SAJ_string(ss, p);
		}
		if (ch == '-' || (ch <= '9' && ch >= '0')) {
			return SAJ_number(ss, p);
		}
		if (ch == 't' || ch == 'f') {
			return SAJ_bool(ss, p);
		}
		if (ch == 'n') {
			return SAJ_null(ss, p);
		}
		//else
		p.error(error_line, "Error: unknowned type");
		return false;
	}
}