#include"JSON_Object.h"
#include"JSON_String.h"
#include"JSON_Parser.h"
#include"JSON_Printer.h"

namespace MyJSON
{
	/*----------parser----------*/
	std::shared_ptr<JSON_Value> JSON_Parser::obj_parser(
			std::istream& ss,
			std::shared_ptr<JSON_Value> fa,
			Parse_State& state)
	{
		state.ignore_blank(ss);
		if (ss.peek() != '{') {
			state.set_error("SyntaxError: The object struct need '{'");
			return nullptr;
		}
		ss.ignore();
		state.ignore_blank(ss);

		std::shared_ptr<JSON_Object> ret = std::make_shared<JSON_Object>();
		ret->set_father(fa);
		if (ss.peek() == '}') {	//{}
			ss.ignore();
			return ret;
		}

		while (ss.peek() != EOF) {
			/*---"key"---*/
			std::string key;
			if(ss.peek()=='"')
			{
				ss.ignore();
				while (ss.peek() != '"' && ss.peek() != EOF)
				{
					key += char(ss.peek());
					ss.ignore();
				}
				if (ss.peek() == '"') {
					ss.ignore();
				} else {
					state.set_error("SyntaxError: Key's '\"' isn't closed");
					return nullptr;
				}
			}
			/*---"key"---*/
			/*---:---*/
			state.ignore_blank(ss);
			if (ss.peek() != ':') {
				state.set_error("SyntaxError: Object struct need ':'");
				return nullptr;
			}ss.ignore();
			/*---:---*/
			/*---value---*/
			std::shared_ptr<JSON_Value> v = std::make_shared<JSON_Value>();
			v = val_parser(ss, ret, state);
			/*---value---*/
			if (!state.get_state()) {
				return nullptr;
			}
			ret->insert(key, v);
			/*---next---*/
			state.ignore_blank(ss);
			if (ss.peek() == ',') {
				ss.ignore();
				continue;
			} else if (ss.peek() == '}') {
				ss.ignore();
				return ret;
			} else {
				state.set_error("SyntaxError: The object struct is not valid");
				return nullptr;
			}
			/*---next---*/
		}//不完整的文件
		state.set_error("FileError: Stream unexpectedly over");
		return nullptr;
	}
	/*----------print----------*/
	void JSON_Printer::obj_printer(std::ostream& os,
								   std::shared_ptr<JSON_Object> self,
								   Print_State state)
	{
		if (self->get_size() == 0) {
			os << "{}";
			return;
		}
		state.tab(true);
		os << "{\n";
		for (auto it = self->get_child().begin(); it != self->get_child().end(); ++it) {
			auto [k, v] = *it;
			for (int i = 0; i < state.tab_deep(); i++) {
				os << '\t';
			}
			os << k << ':';
			if (v->get_type() == JOBJECT || v->get_type() == JARRAY) {
				os << v;
			} else {
				os << ' ' << v;
			}
			if (std::next(it) != self->get_child().end()) {
				os << ',';
			}
			os << '\n';
		}
		state.tab(false);
		for (int i = 0; i < state.tab_deep(); i++) {
			os << '\t';
		}
		os << '}';
		return;
	}
}