#pragma once
#include"JSON_Value.h"

namespace MyJSON
{
	class JSON_Bool: public JSON_Value
	{
		bool value_ = false;

	public:
		std::shared_ptr<JSON_Value> parser(std::stringstream& ss) override;
		std::ostream& print(std::ostream& os) override;

		bool get_value()
		{
			return value_;
		}
		void set_value(bool _v)
		{
			value_ = _v;
		}

		JSON_Bool():JSON_Value(JBOOL) {}
		~JSON_Bool() {}
	};
}