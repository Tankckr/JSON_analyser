#pragma once
#include"JSON_Value.h"
#include"JSON_Error.h"

namespace MyJSON
{
	class JSON_NULL: public JSON_Value
	{
	public:
		std::shared_ptr<JSON_Value> parser(
			std::istream& ss,
			std::shared_ptr<JSON_Value> fa) override;
		std::ostream& print(std::ostream& os) override;

		JSON_NULL():JSON_Value(JNULL) {}
		virtual ~JSON_NULL() {}
	};
}