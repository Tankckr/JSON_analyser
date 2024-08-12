#include"JSON_Bool.h"
#include"JSON_Parser.h"
#include"JSON_Printer.h"

namespace MyJSON
{
	/*----------parser----------*/
	std::shared_ptr<JSON_Value> JSON_Parser::boo_parser(
			std::istream& ss,
			std::shared_ptr<JSON_Value> fa,
			Parse_State& state)
	{
		state.ignore_blank(ss);
		if (ss.peek() == 't') {
			ss.ignore();
			if (ss.peek() == 'r') {
				ss.ignore();
				if (ss.peek() == 'u') {
					ss.ignore();
					if (ss.peek() == 'e') {
						ss.ignore();
						std::shared_ptr<JSON_Bool> ret = std::make_shared<JSON_Bool>();
						ret->set_father(fa);
						ret->set_value(true);
						return ret;
					}
				}
			}
		} else if (ss.peek() == 'f') {
			ss.ignore();
			if (ss.peek() == 'a') {
				ss.ignore();
				if (ss.peek() == 'l') {
					ss.ignore();
					if (ss.peek() == 's') {
						ss.ignore();
						if (ss.peek() == 'e') {
							ss.ignore();
							std::shared_ptr<JSON_Bool> ret = std::make_shared<JSON_Bool>();
							ret->set_father(fa);
							ret->set_value(false);
							return ret;
						}
					}
				}
			}
		}
		state.set_error("TypeError: Unknowned Value Type");
		return nullptr;
	}
	/*----------print----------*/
	void JSON_Printer::boo_printer(std::ostream& os,
								   std::shared_ptr<JSON_Bool> self)
	{
		if (self->get_value()) {
			os << "true";
		} else {
			os << "false";
		}
		return;
	}
}