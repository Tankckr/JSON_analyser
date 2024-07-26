#pragma once
#include"JSON_Value.h"

namespace MyJSON
{
	class JSON_Array: public JSON_Value
	{
		std::vector<std::shared_ptr<JSON_Value>> child_;

	public:
		std::shared_ptr<JSON_Value> parser(std::stringstream& ss) override;
		std::ostream& print(std::ostream& os) override;

		std::shared_ptr<JSON_Value> operator [] (int index)
		{
			return child_[index];
		}
		int get_size()
		{
			return child_.size();
		}
		///position in [0~size]
		void insert(int pos, std::shared_ptr<JSON_Value> value)
		{
			child_.insert(child_.begin() + pos, value);
		}

		JSON_Array():JSON_Value(JARRAY) {}
		~JSON_Array() {}
	};
}