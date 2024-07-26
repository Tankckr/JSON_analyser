#include"JSON_Error.h"

namespace MyJSON
{
	/*----------print----------*/
	std::ostream& JSON_Error::print(std::ostream& os)
	{
		os << error_type_ << "\nin line " << error_line << '\n';
		os << error_pos_ << "->" << error_code_ << '\n';
		return os;
	}
}