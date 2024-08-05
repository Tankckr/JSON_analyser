#include"JSON_Bool.h"
#include"JSON_Error.h"

namespace MyJSON
{
	/*----------parser----------*/
	std::shared_ptr<JSON_Value> JSON_Bool::parser(
			std::istream& ss,
			std::shared_ptr<JSON_Value> fa)
	{
		ignore_blank(ss);
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
		return std::make_shared<JSON_Error>(ss,
											ss.tellg(),
											syntax_error_unknown_type);
	}
	/*----------print----------*/
	std::ostream& JSON_Bool::print(std::ostream& os)
	{
		if (value_) {
			os << "true";
		} else {
			os << "false";
		}
		return os;
	}
}