#include"SAJ.h"
#include<regex>

namespace SAJ
{
	bool SAJ_Parser::SAJ_number(std::istream& ss, SAJ_Processor& p)
	{
		ignore_blank(ss);
		std::string ms = "";
		while (ss.peek() == '-' || ss.peek() == '+' ||
			   ss.peek() == '.' || (ss.peek() >= '0' && ss.peek() <= '9') ||
			   ss.peek() == 'e' || ss.peek() == 'E')
		{
			if (ss.peek() == EOF) {
				break;
			}
			ms += ss.peek();
			ss.ignore();
		}
		std::smatch match;
		std::regex number(
			"^-?([0]|[1-9][0-9]*)(\\.[0-9]{1,})?([e|E][+|-]?[1-9][0-9]*)?");
		if (std::regex_search(ms, match, number)) {
			bool value_type = false;
			std::string value = match.str();
			// figure int or double
			for (int i = 0; i < value.size(); i++) {
				if (value[i] == '.' || value[i] == 'e' || value[i] == 'E') {
				value_type = true;
				}
			}
			if (value_type) {
				try {
					double value_double = std::stod(value);
					p.number_double(value_double);
					return true;
				} catch (const std::out_of_range& e) {
					p.number_out_of_range(value);
					return true;
				}
			} else {
				try {
					int64_t value_int = std::stoll(value);
					p.number_int(value_int);
					return true;
				} catch (const std::out_of_range& e) {
					p.number_out_of_range(value);
					return true;
				}
			}
		} else {
			std::string error_code;
			getline(ss, error_code);
			p.error(error_line, "Error: number invalid");
			return false;
		}
	}
}