#pragma once
#include"JSON_Value.h"

namespace MyJSON
{
	class JSON_Printer
	{
		Print_State state_;
	public:
		static void val_printer(std::ostream& os,
								std::shared_ptr<JSON_Value> self,
								Print_State);
		static void obj_printer(std::ostream& os,
								std::shared_ptr<JSON_Object> self,
								Print_State);
		static void arr_printer(std::ostream& os,
								std::shared_ptr<JSON_Array> self,
								Print_State);
		static void str_printer(std::ostream& os,
								std::shared_ptr<JSON_String> self);
		static void num_printer(std::ostream& os,
								std::shared_ptr<JSON_Number> self);
		static void boo_printer(std::ostream& os,
								std::shared_ptr<JSON_Bool> self);
		static void nul_printer(std::ostream& os);

		bool print(std::ostream& os, JSON_Value& val);

		bool get_state()
		{
			return state_.get_state();
		}

		void print_error(std::ostream& os = std::cerr)
		{
			state_.print_error(os);
		}
	};

	class Print_State
	{
		bool state_ = true;
		std::string error_info_;
		int tab_deep_ = 0;

	public:
		void tab(bool ob)
		{
			if (ob) {
				tab_deep_++;
			} else {
				tab_deep_--;
			}
		}
		int tab_deep()
		{
			return tab_deep_;
		}
		bool get_state()
		{
			return state_;
		}
		// Error
		void set_error(std::string ei)
		{
			state_ = false;
			error_info_ = ei;
		}
		void print_error(std::ostream& os);
	};
}