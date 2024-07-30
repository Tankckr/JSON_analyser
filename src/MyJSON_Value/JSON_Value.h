#pragma once
#include"Global_JSON.h"

namespace MyJSON
{
	class JSON_Value: public std::enable_shared_from_this<JSON_Value>
	{
		JSON_Type type_ = JINITIAL;
		std::shared_ptr<JSON_Value> father_;

	public:
		JSON_Type get_type()
		{
			return type_;
		}
		std::shared_ptr<JSON_Object> get_obj();
		std::shared_ptr<JSON_Array> get_arr();
		std::shared_ptr<JSON_String> get_str();
		std::shared_ptr<JSON_Number> get_num();
		std::shared_ptr<JSON_Bool> get_boo();
		std::shared_ptr<JSON_NULL> get_nul();
		std::shared_ptr<JSON_Value> get_father()
		{
			return father_;
		}
		void set_father(std::shared_ptr<JSON_Value> f)
		{
			father_ = f;
		}

		std::shared_ptr<JSON_Value> parser(
				std::istream& is,
				std::shared_ptr<JSON_Value> fa = nullptr);
		virtual std::shared_ptr<JSON_Value> parser(
				std::stringstream& ss,
				std::shared_ptr<JSON_Value> fa = nullptr);

		virtual std::ostream& print(std::ostream& os);

		JSON_Value(JSON_Type _type = JINITIAL): type_(_type)
		{}
		virtual ~JSON_Value() {}
	};
}