#include"JSON_Printer.h"

namespace MyJSON
{
	bool JSON_Printer::print(std::ostream& os, JSON_Value& val)
	{
		std::shared_ptr<JSON_Value> p = val.shared_from_this();
		val_printer(os, p, state_);
		if (!get_state())
		{
			return false;
		}
		return true;
	}

	void Print_State::print_error(std::ostream& os)
	{
		os << error_info_ << '\n';
	}
}