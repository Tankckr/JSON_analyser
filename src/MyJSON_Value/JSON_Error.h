#pragma once
#include"JSON_Value.h"

namespace MyJSON
{
	class JSON_Error: public JSON_Value
	{
		std::string error_type_;
		const int error_pos_;
		std::string error_code_ = "?";
	public:

		std::ostream& print(std::ostream& os) override;

		JSON_Error(std::istream& ss, int p = 0, std::string e = no_error):
			JSON_Value(JERROR),
			error_type_(e),
			error_pos_(p)
		{
			ss.seekg(error_pos_);
			getline(ss, error_code_);
		}

		virtual ~JSON_Error() {}
	};
}