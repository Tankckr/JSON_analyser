#pragma once
#include"JSON_Value.h"
#include<unordered_map>

namespace MyJSON
{
	class JSON_Object: public JSON_Value
	{
		std::unordered_map<std::string, std::shared_ptr<JSON_Value>> child_;
		/// @brief 在解析器中调用的插入（解析器中通过string的parser获取的key是带""的）
		/// @param key 
		/// @param value 
		void parser_insert(std::string key, std::shared_ptr<JSON_Value> value)
		{
			child_.insert({ key,value });
		}
	public:
		// std::shared_ptr<JSON_Value> parser(
		// 	std::istream& ss,
		// 	std::shared_ptr<JSON_Value> fa) override;
		// std::ostream& print(std::ostream& os) override;

		std::shared_ptr<JSON_Value> operator [] (std::string key)
		{
			return child_[key];
		}
		int get_size()
		{
			return child_.size();
		}
		std::unordered_map<std::string, std::shared_ptr<JSON_Value>>&
		get_child()
		{
			return child_;
		}
		void insert(std::string key, std::shared_ptr<JSON_Value> value)
		{
			value->set_father(shared_from_this());
			child_.insert({ key,value });
		}

		JSON_Object():JSON_Value(JOBJECT) {}
		virtual ~JSON_Object() {}
	};
}
