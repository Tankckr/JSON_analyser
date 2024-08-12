#include"JSON_Array.h"
#include"JSON_Parser.h"
#include"JSON_Printer.h"

namespace MyJSON
{
	/*----------parser----------*/
	std::shared_ptr<JSON_Value> JSON_Parser::arr_parser(
			std::istream& ss,
			std::shared_ptr<JSON_Value> fa,
			Parse_State& state)
	{
		state.ignore_blank(ss);
		if (ss.peek() != '[') {
			state.set_error("SyntaxError: The array struct need '['");
			return nullptr;
		}
		ss.ignore();
		state.ignore_blank(ss);

		std::shared_ptr<JSON_Array> ret = std::make_shared<JSON_Array>();
		ret->set_father(fa);
		if (ss.peek() == ']') {
			ss.ignore();
			return ret;
		}

		while (ss.peek() != EOF) {
			/*---value---*/
			std::shared_ptr<JSON_Value> v = std::make_shared<JSON_Value>();
			v = val_parser(ss, ret, state);
			/*---value---*/
			if (!state.get_state()) {
				return nullptr;
			}
			ret->insert(ret->get_size(), v);
			/*---next---*/
			state.ignore_blank(ss);
			if (ss.peek() == ',') {
				ss.ignore();
				continue;
			} else if (ss.peek() == ']') {
				ss.ignore();
				return ret;
			} else {
				state.set_error("SyntaxError: The array struct is not valid");
				return nullptr;
			}
			/*---next---*/
		}
		state.set_error("FileError: Stream unexpectedly over");
		return nullptr;
	}
	/*----------print----------*/
	void JSON_Printer::arr_printer(std::ostream& os,
								   std::shared_ptr<JSON_Array> self,
								   Print_State state)
	{
		if (self->get_size() == 0) {
			os << "[]";
			return;
		}
		state.tab(true);
		os << "[\n";
		int n = self->get_size();
		for (int i = 0; i < n; i++) {
			for (int i = 0; i < state.tab_deep(); i++) {
				os << '\t';
			}
			os << self->get_child()[i];
			if (i != n - 1) {
				os << ',';
			}
			os << '\n';
		}
		state.tab(false);
		for (int i = 0; i < state.tab_deep(); i++) {
			os << '\t';
		}
		os << ']';
		return;
	}
}