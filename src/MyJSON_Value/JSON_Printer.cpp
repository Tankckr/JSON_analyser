#include"JSON_Printer.h"

namespace MyJSON
{
	bool JSON_Printer::print(std::ostream& os, JSON_Value& val)
	{
		std::shared_ptr<JSON_Value> p(&val);
		val_printer(os, p, state_);
		if (!get_state())
		{
			return false;
		}
	}

	void Print_State::print_error(std::ostream& os)
	{
		os << error_info_ << '\n';
	}
}