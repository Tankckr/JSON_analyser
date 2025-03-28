#include"JSON_Array.h"
#include"JSON_Error.h"

namespace MyJSON
{
	/*----------parser----------*/
	std::shared_ptr<JSON_Value> JSON_Array::parser(
			std::istream& ss,
			std::shared_ptr<JSON_Value> fa)
	{
		ignore_blank(ss);
		if (ss.peek() != '[') {
			return std::make_shared<JSON_Error>(ss,
												ss.tellg(),
												syntax_error_array);
		}
		ss.ignore();

		std::shared_ptr<JSON_Array> ret = std::make_shared<JSON_Array>();
		ret->set_father(fa);
		ignore_blank(ss);
		if (ss.peek() == ']') {
			ss.ignore();
			return ret;
		}

		while (ss.peek() != EOF) {
			/*---value---*/
			std::shared_ptr<JSON_Value> p = std::make_shared<JSON_Value>();
			p = p->parser(ss, ret);
			/*---value---*/
			if (p->get_type() == JERROR) {
				return p;
			}
			// ret->insert(get_size(), p);
			ret->child_.push_back(p);
			/*---next---*/
			ignore_blank(ss);
			if (ss.peek() == ',') {
				ss.ignore();
				continue;
			} else if (ss.peek() == ']') {
				ss.ignore();
				return ret;
			} else {
				std::cout << "i haven't got , !\n";
				return std::make_shared<JSON_Error>(ss,
													ss.tellg(),
													syntax_error_array);
			}
			/*---next---*/
		}
		return std::make_shared<JSON_Error>(ss, ss.tellg(), error_broken_file);
	}
	/*----------print----------*/
	std::ostream& JSON_Array::print(std::ostream& os)
	{
		if (get_size() == 0) {
			os << "[]";
			return os;
		}
		tab_deep++;
		os << "[\n";
		int n = child_.size();
		for (int i = 0; i < n; i++) {
			for (int i = 0; i < tab_deep; i++) {
				os << '\t';
			}
			os << child_[i];
			if (i != n - 1) {
				os << ',';
			}
			os << '\n';
		}
		tab_deep--;
		for (int i = 0; i < tab_deep; i++) {
			os << '\t';
		}
		os << ']';
		return os;
	}
}