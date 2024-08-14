#include"src/MyJSON.h"
#include"src/SAJ/SAJ.h"

using namespace MyJSON;
using namespace SAJ;

class MyJSON_Processor:public SAJ_Processor
{
	std::shared_ptr<JSON_Value> root_;
	std::shared_ptr<JSON_Value> cur_;
	std::string key_;
	bool has_key_ = false;
	bool file_start_ = false;

	virtual void parse_start() override
	{
		file_start_ = true;
		std::cout << "parse start!\n";
	}
	virtual void parse_end() override
	{
		std::cout << "parse end\n";
	}
	virtual void object_start() override
	{
		std::cout << "object start\n";
		if (has_key_) {
			std::shared_ptr<JSON_Object> o = std::make_shared<JSON_Object>();
			o->set_father(cur_);
			cur_->get_obj()->insert(key_, o);
			cur_ = o;
			has_key_ = false;
		} else {
			//file start or in array
			if (file_start_) {
				root_ = std::make_shared<JSON_Object>();
				cur_ = root_;
				file_start_ = false;
			} else {
				std::shared_ptr<JSON_Object> o = std::make_shared<JSON_Object>();
				o->set_father(cur_);
				cur_->get_arr()->insert(cur_->get_arr()->get_size(), o);
				cur_ = o;
			}
		}
	}
	virtual void object_end() override
	{
		cur_ = cur_->get_father();
		std::cout << "object end\n";
	}
	virtual void object_key(std::string k) override
	{
		std::cout << "key: " << k << std::endl;
		key_ = k;
		has_key_ = true;
	}
	virtual void array_start() override
	{
		std::cout << "array start\n";
		if (has_key_) {
			std::shared_ptr<JSON_Array> a = std::make_shared<JSON_Array>();
			a->set_father(cur_);
			cur_->get_obj()->insert(key_, a);
			cur_ = a;
			has_key_ = false;
		} else {
			if (file_start_) {
				root_ = std::make_shared<JSON_Array>();
				cur_ = root_;
				file_start_ = false;
			} else {
				std::shared_ptr<JSON_Array> a = std::make_shared<JSON_Array>();
				a->set_father(cur_);
				cur_->get_arr()->insert(cur_->get_arr()->get_size(), a);
				cur_ = a;
			}
		}
	}
	virtual void array_end() override
	{
		cur_ = cur_->get_father();
		std::cout << "array end\n";
	}
	virtual void string(std::string str) override
	{
		std::cout << "string: " << str << '\n';
		if (has_key_) {
			std::shared_ptr<JSON_String> s = std::make_shared<JSON_String>();
			s->set_father(cur_);
			s->set_value(str);
			cur_->get_obj()->insert(key_, s);
			has_key_ = false;
		} else {
			if (file_start_) {
				root_ = std::make_shared<JSON_String>();
				cur_ = root_;
				cur_->get_str()->set_value(str);
				file_start_ = false;
			} else {
				std::shared_ptr<JSON_String> s = std::make_shared<JSON_String>();
				s->set_father(cur_);
				s->set_value(str);
				cur_->get_arr()->insert(cur_->get_arr()->get_size(), s);
			}
		}
	}
	virtual void number_int(int64_t i) override
	{
		std::cout << "number: " << i << '\n';
		if (has_key_) {
			std::shared_ptr<JSON_Number> n = std::make_shared<JSON_Number>();
			n->set_father(cur_);
			n->set_value(std::to_string(i));
			cur_->get_obj()->insert(key_, n);
			has_key_ = false;
		} else {
			if (file_start_) {
				root_ = std::make_shared<JSON_Number>();
				cur_ = root_;
				cur_->get_num()->set_value(std::to_string(i));
				file_start_ = false;
			} else {
				std::shared_ptr<JSON_Number> n = std::make_shared<JSON_Number>();
				n->set_father(cur_);
				n->set_value(std::to_string(i));
				cur_->get_arr()->insert(cur_->get_arr()->get_size(), n);
			}
		}
	}
	virtual void number_double(double d) override
	{
		std::cout << "number: " << d << '\n';
		if (has_key_) {
			std::shared_ptr<JSON_Number> n = std::make_shared<JSON_Number>();
			n->set_father(cur_);
			n->set_value(std::to_string(d));
			cur_->get_obj()->insert(key_, n);
			has_key_ = false;
		} else {
			if (file_start_) {
				root_ = std::make_shared<JSON_Number>();
				cur_ = root_;
				cur_->get_num()->set_value(std::to_string(d));
				file_start_ = false;
			} else {
				std::shared_ptr<JSON_Number> n = std::make_shared<JSON_Number>();
				n->set_father(cur_);
				n->set_value(std::to_string(d));
				cur_->get_arr()->insert(cur_->get_arr()->get_size(), n);
			}
		}
	}
	virtual void number_out_of_range(std::string str) override
	{
		std::cout << "number: " << str << '\n';
		if (has_key_) {
			std::shared_ptr<JSON_Number> n = std::make_shared<JSON_Number>();
			n->set_father(cur_);
			n->set_value(str);
			cur_->get_obj()->insert(key_, n);
			has_key_ = false;
		} else {
			if (file_start_) {
				root_ = std::make_shared<JSON_Number>();
				cur_ = root_;
				cur_->get_num()->set_value(str);
				file_start_ = false;
			} else {
				std::shared_ptr<JSON_Number> n = std::make_shared<JSON_Number>();
				n->set_father(cur_);
				n->set_value(str);
				cur_->get_arr()->insert(cur_->get_arr()->get_size(), n);
			}
		}
	}
	virtual void boolean(bool b) override
	{
		std::cout << b ? "true\n" : "false\n";
		if (has_key_) {
			std::shared_ptr<JSON_Bool> n = std::make_shared<JSON_Bool>();
			n->set_father(cur_);
			n->set_value(b);
			cur_->get_obj()->insert(key_, n);
			has_key_ = false;
		} else {
			if (file_start_) {
				root_ = std::make_shared<JSON_Bool>();
				cur_ = root_;
				cur_->get_boo()->set_value(b);
				file_start_ = false;
			} else {
				std::shared_ptr<JSON_Bool> n = std::make_shared<JSON_Bool>();
				n->set_father(cur_);
				n->set_value(b);
				cur_->get_arr()->insert(cur_->get_arr()->get_size(), n);
			}
		}
	}
	virtual void null() override
	{
		std::cout << "null\n";
		if (has_key_) {
			std::shared_ptr<JSON_NULL> n = std::make_shared<JSON_NULL>();
			n->set_father(cur_);
			cur_->get_obj()->insert(key_, n);
			has_key_ = false;
		} else {
			if (file_start_) {
				root_ = std::make_shared<JSON_NULL>();
				cur_ = root_;
				file_start_ = false;
			} else {
				std::shared_ptr<JSON_NULL> n = std::make_shared<JSON_NULL>();
				n->set_father(cur_);
				cur_->get_arr()->insert(cur_->get_arr()->get_size(), n);
			}
		}
	}
	virtual void error(int error_line,
		std::string error_info) override
	{
		std::cout << "lines " << error_line << '\n';
		std::cout << error_info << '\n';
	}

public:
	std::shared_ptr<JSON_Value> get_root()
	{
		return root_;
	}
};

#include <fstream>
int main()
{
	MyJSON_Processor pro;
	std::ifstream file("../test_sample2.json");
	if (file.is_open()) {
		std::stringstream ss;
		ss << file.rdbuf();
		parse_to_SAJ(ss, pro);
		JSON_Printer Pt;
		Pt.print(std::cout, *pro.get_root().get());
	} else
		std::cout << "open failed\n";
}