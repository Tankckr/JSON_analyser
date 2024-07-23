#pragma once
#include"JSON_Value.h"

namespace MyJSON
{
	class JSON_Object: public JSON_Value
	{
		std::unordered_map<std::string, std::shared_ptr<JSON_Value>> child_;

	public:
		std::shared_ptr<JSON_Value> parser(std::stringstream& ss) override;
		std::ostream& print(std::ostream& os) override;

		std::shared_ptr<JSON_Value> operator [] (std::string key)
		{
			return child_['"' + key + '"'];
		}
		int get_size()
		{
			return child_.size();
		}
		void insert(std::string key, std::shared_ptr<JSON_Value> value)
		{
			child_.insert({ key,value });
		}

		JSON_Object():JSON_Value(JOBJECT) {}
		~JSON_Object() {}
	};
}
