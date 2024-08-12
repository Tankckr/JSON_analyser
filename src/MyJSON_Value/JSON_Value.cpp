#include"JSON_Parser.h"
#include"JSON_Printer.h"

namespace MyJSON
{
	/*----------get_pointer----------*/
	std::shared_ptr<JSON_Object> JSON_Value::get_obj()
	{
		if (type_ != JOBJECT) {
			std::cerr << "\niwanna JOBJECT, your type:"
					  << type_string(type_) << '\n';
			throw "type Error!";
		}
		return std::dynamic_pointer_cast<JSON_Object>(shared_from_this());
	}
	std::shared_ptr<JSON_Array> JSON_Value::get_arr()
	{
		if (type_ != JARRAY) {
			std::cerr << "\niwanna JARRAY, your type:"
					  << type_string(type_) << '\n';
			throw "type Error!";
		}
		return std::dynamic_pointer_cast<JSON_Array>(shared_from_this());
	}
	std::shared_ptr<JSON_String> JSON_Value::get_str()
	{
		if (type_ != JSTRING) {
			std::cerr << "\niwanna JSTRING, your type:"
					  << type_string(type_) << '\n';
			throw "type Error!";
		}
		return std::dynamic_pointer_cast<JSON_String>(shared_from_this());
	}
	std::shared_ptr<JSON_Number> JSON_Value::get_num()
	{
		if (type_ != JNUMBER) {
			std::cerr << "\niwanna JNUMBER, your type:"
					  << type_string(type_) << '\n';
			throw "type Error!";
		}
		return std::dynamic_pointer_cast<JSON_Number>(shared_from_this());
	}
	std::shared_ptr<JSON_Bool> JSON_Value::get_boo()
	{
		if (type_ != JBOOL) {
			std::cerr << "\niwanna JBOOL, your type:"
					  << type_string(type_) << '\n';
			throw "type Error!";
		}
		return std::dynamic_pointer_cast<JSON_Bool>(shared_from_this());
	}
	std::shared_ptr<JSON_NULL> JSON_Value::get_nul()
	{
		if (type_ != JNULL) {
			std::cerr << "\niwanna JNULL, your type:"
					  << type_string(type_) << '\n';
			throw "type Error!";
		}
		return std::dynamic_pointer_cast<JSON_NULL>(shared_from_this());
	}

	/*----------parser----------*/

	/// @brief 
	/// @param std::istream& ss
	/// @return std::shared_ptr<JSON_Value>
	std::shared_ptr<JSON_Value> JSON_Parser::val_parser(
			std::istream& is,
			std::shared_ptr<JSON_Value> fa,
			Parse_State& state)
	{
		state.ignore_blank(is);
		char ch = is.peek();
		if (ch == '{') {
			std::shared_ptr<JSON_Value> ret = obj_parser(is, fa, state);
			return ret;
		}
		if (ch == '[') {
			std::shared_ptr<JSON_Value> ret = arr_parser(is, fa, state);
			return ret;
		}
		if (ch == '"') {
			std::shared_ptr<JSON_Value> ret = str_parser(is, fa, state);
			return ret;
		}
		if (ch == '-' || (ch <= '9' && ch >= '0')) {
			std::shared_ptr<JSON_Value> ret = num_parser(is, fa, state);
			return ret;
		}
		if (ch == 't' || ch == 'f') {
			std::shared_ptr<JSON_Value> ret = boo_parser(is, fa, state);
			return ret;
		}
		if (ch == 'n') {
			std::shared_ptr<JSON_Value> ret = nul_parser(is, fa, state);
			return ret;
		}
		state.set_error("TypeError: Unknowned Value Type");
		return nullptr;
	}
	/*----------print----------*/
	void JSON_Printer::val_printer(std::ostream& os,
								   std::shared_ptr<JSON_Value> self)
	{
		switch (self->get_type())
		{
		case JINITIAL:
			{
				os << "PrintError: Void JSON_Value struct can not be printed";
				break;
			}
		case JOBJECT:
			{
				JSON_Printer::obj_printer(os, self->get_obj());
				break;
			}
		case JARRAY:
			{
				JSON_Printer::arr_printer(os, self->get_arr());
				break;
			}
		case JSTRING:
			{
				JSON_Printer::str_printer(os, self->get_str());
				break;
			}
		case JNUMBER:
			{
				JSON_Printer::num_printer(os, self->get_num());
				break;
			}
		case JBOOL:
			{
				JSON_Printer::boo_printer(os, self->get_boo());
				break;
			}
		case JNULL:
			{
				JSON_Printer::nul_printer(os, self->get_nul());
				break;
			}
		default:
			{
				os << "PrintError: Unknowned JSON_Type";
				break;
			}
		}
	}
}