#include"JSON_Parser.h"

namespace MyJSON
{
	bool JSON_Parser::parse(std::istream& is, JSON_Value& val)
	{
		std::shared_ptr<JSON_Value> p;
		p = val_parser(is, nullptr, state_);
		if (!get_state())
		{
			return false;
		}
		//如何从shared_ptr<JSON_Value>转化到JSON_Value还是个问题 orz
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
}