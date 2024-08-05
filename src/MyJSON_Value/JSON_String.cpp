#include"JSON_String.h"
#include"JSON_Error.h"

namespace MyJSON
{
	/*----------parser----------*/
	std::shared_ptr<JSON_Value> JSON_String::parser(
			std::istream& ss,
			std::shared_ptr<JSON_Value> fa)
	{
		ignore_blank(ss);
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
				return std::make_shared<JSON_Error>(ss,
													ss.tellg(),
													error_broken_file);
			}
		} else {
			return std::make_shared<JSON_Error>(ss,
												ss.tellg(),
												syntax_error_string);
		}
	}
	/*----------print----------*/
	std::ostream& JSON_String::print(std::ostream& os)
	{
		os << '"' << value_ << '"';
		return os;
	}
}