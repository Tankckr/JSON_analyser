#include"../MyJSON.h"

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
	std::shared_ptr<JSON_Value> JSON_Value::parser(std::ifstream& fs)
	{
		std::stringstream ss;
		ss << fs.rdbuf();
		return parser(ss);
	}
	/// @brief JSON_value的parser不会变更自身指针，如果在最外层处理的时候记得获取返回值
	/// @param std::stringstream& ss
	/// @return std::shared_ptr<JSON_Value>
	std::shared_ptr<JSON_Value> JSON_Value::parser(
			std::stringstream& ss,
			std::shared_ptr<JSON_Value> fa)
	{
		ignore_blank(ss);
		char ch = ss.peek();
		if (ch == '{') {
			std::shared_ptr<JSON_Object> ret = std::make_shared<JSON_Object>();
			return ret->parser(ss, fa);
		}
		if (ch == '[') {
			std::shared_ptr<JSON_Array> ret = std::make_shared<JSON_Array>();
			return ret->parser(ss, fa);
		}
		if (ch == '"') {
			std::shared_ptr<JSON_String> ret = std::make_shared<JSON_String>();
			return ret->parser(ss, fa);
		}
		if (ch == '-' || (ch <= '9' && ch >= '0')) {
			std::shared_ptr<JSON_Number> ret = std::make_shared<JSON_Number>();
			return ret->parser(ss, fa);
		}
		if (ch == 't' || ch == 'f') {
			std::shared_ptr<JSON_Bool> ret = std::make_shared<JSON_Bool>();
			return ret->parser(ss, fa);
		}
		if (ch == 'n') {
			std::shared_ptr<JSON_NULL> ret = std::make_shared<JSON_NULL>();
			return ret->parser(ss, fa);
		}
		//else
		return std::make_shared<JSON_Error>(ss,
											ss.tellg(),
											syntax_error_unknown_type);
	}
	/*----------print----------*/
	std::ostream& JSON_Value::print(std::ostream& os)
	{
		throw "Error: JSON_Value cannot be printed!\n";
	}
}