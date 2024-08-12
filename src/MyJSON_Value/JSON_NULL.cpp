#include"JSON_NULL.h"
#include"JSON_Parser.h"
#include"JSON_Printer.h"

namespace MyJSON
{
	/*----------parser----------*/
	std::shared_ptr<JSON_Value> JSON_Parser::nul_parser(
			std::istream& ss,
			std::shared_ptr<JSON_Value> fa,
			Parse_State& state)
	{
		state.ignore_blank(ss);
		if (ss.peek() == 'n') {
			ss.ignore();
			if (ss.peek() == 'u') {
				ss.ignore();
				if (ss.peek() == 'l') {
					ss.ignore();
					if (ss.peek() == 'l') {
						ss.ignore();
						std::shared_ptr<JSON_NULL> ret = std::make_shared<JSON_NULL>();
						ret->set_father(fa);
						return ret;
					}
				}
			}
		}
		state.set_error("TypeError: Unknowned Value Type");
		return nullptr;
	}
	/*----------print----------*/
	void JSON_Printer::nul_printer(std::ostream& os)
	{
		os << "null";
		return;
	}
}
