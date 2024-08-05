#include"JSON_NULL.h"

namespace MyJSON
{
	/*----------parser----------*/
	std::shared_ptr<JSON_Value> JSON_NULL::parser(
			std::istream& ss,
			std::shared_ptr<JSON_Value> fa)
	{
		ignore_blank(ss);
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
		return std::make_shared<JSON_Error>(ss,
											ss.tellg(),
											syntax_error_unknown_type);
		// std::string ms = ss.str().substr(ss.tellg());
		// std::smatch match;
		// std::regex N("^(null)");
		// if (std::regex_search(ms, match, N)) {
		// 	std::shared_ptr<JSON_NULL> ret = std::make_shared<JSON_NULL>();
		// 	ret->set_father(fa);
		// 	ss.ignore(4);
		// 	return ret;
		// } else {
		// 	return std::make_shared<JSON_Error>(ss,
		// 										ss.tellg(),
		// 										syntax_error_unknown_type);
		// }
	}
	/*----------print----------*/
	std::ostream& JSON_NULL::print(std::ostream& os)
	{
		os << "null";
		return os;
	}
}
