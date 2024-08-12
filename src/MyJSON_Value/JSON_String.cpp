#include"JSON_String.h"
#include"JSON_Parser.h"
#include"JSON_Printer.h"

namespace MyJSON
{
	/*----------parser----------*/
	std::shared_ptr<JSON_Value> JSON_Parser::str_parser(
			std::istream& ss,
			std::shared_ptr<JSON_Value> fa,
			Parse_State& state)
	{
		state.ignore_blank(ss);
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
				std::shared_ptr<JSON_String> ret =
					std::make_shared<JSON_String>();
				ret->set_father(fa);
				ret->set_value(str);
				return ret;
			} else {
				state.set_error("FileError: Stream unexpectedly over");
				return nullptr;
			}
		} else {
			state.set_error("SyntaxError: The string struct need '\"'");
			return nullptr;
		}
	}
	/*----------print----------*/
	void JSON_Printer::str_printer(std::ostream& os,
								   std::shared_ptr<JSON_String> self)
	{
		os << '"' << self->get_value() << '"';
		return;
	}
}