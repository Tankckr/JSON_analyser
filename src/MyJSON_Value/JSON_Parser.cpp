#include"JSON_Parser.h"

namespace MyJSON
{
	std::shared_ptr<JSON_Value> JSON_Parser::parse(std::istream& is)
	{
		std::shared_ptr<JSON_Value> p;
		p = val_parser(is, p, state_);
		if (!get_state())
		{
			return nullptr;
		}
		return p;
	}

	void Parse_State::ignore_blank(std::istream& is)
	{
		while (is.peek() > 0 && is.peek() <= 32) {
			if (is.peek() == '\n') {
				error_line_++;
			}
			is.ignore();
		}
	}
	void Parse_State::print_error(std::ostream& os)
	{
		os << error_info_ << '\n';
		os << "in line " << error_line_ << '\n';
	}
}