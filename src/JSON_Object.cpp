#include"JSON_Object.h"
#include"JSON_String.h"
#include"JSON_Error.h"

namespace MyJSON
{
	/*----------parser----------*/
	std::shared_ptr<JSON_Value> JSON_Object::parser(std::stringstream& ss)
	{
		ignore_blank(ss);
		if (ss.peek() != '{') {
			return std::make_shared<JSON_Error>(ss, ss.tellg(), syntax_error_object);
		}ss.ignore();
		ignore_blank(ss);
		if (ss.peek() == '}') {	//{}
			ss.ignore();
			return std::make_shared<JSON_Object>();
		}

		std::shared_ptr<JSON_Object> ret(new JSON_Object);
		while (ss.peek() != EOF) {
			/*---"key"---*/
			std::shared_ptr<JSON_String> pS = std::make_shared<JSON_String>();
			pS = pS->parser(ss)->get_str();
			if (pS->get_type() == JERROR) {
				return pS;
			}
			std::string key = pS->get_value();
			/*---"key"---*/
			/*---:---*/
			ignore_blank(ss);
			if (ss.peek() != ':') {
				int a = ss.tellg();
				return std::make_shared<JSON_Error>(ss, ss.tellg(), syntax_error_object);
			}ss.ignore();
			/*---:---*/
			/*---value---*/
			std::shared_ptr<JSON_Value> pV = std::make_shared<JSON_Value>();
			pV = pV->parser(ss);
			/*---value---*/
			if (pV->get_type() == JERROR) {
				return pV;
			}
			ret->parser_insert(key, pV);
			/*---next---*/
			ignore_blank(ss);
			if (ss.peek() == ',') {
				ss.ignore();
				continue;
			} else if (ss.peek() == '}') {
				ss.ignore();
				return ret;
			} else return std::make_shared<JSON_Error>(ss, ss.tellg(), syntax_error_object);
			/*---next---*/
		}//不完整的文件
		return std::make_shared<JSON_Error>(ss, ss.tellg(), error_broken_file);
	}
	/*----------print----------*/
	std::ostream& JSON_Object::print(std::ostream& os)
	{
		if (get_size() == 0) {
			os << "{}";
			return os;
		}
		tab_deep++;
		os << "{\n";
		for (auto it = child_.begin(); it != child_.end(); ++it) {
			auto [k, v] = *it;
			for (int i = 0; i < tab_deep; i++) {
				os << '\t';
			}
			os << k << ':';
			if (v->get_type() == JOBJECT || v->get_type() == JARRAY) {
				os << v;
			} else {
				os << ' ' << v;
			}
			if (std::next(it) != child_.end()) {
				os << ',';
			}
			os << '\n';
		}
		tab_deep--;
		for (int i = 0; i < tab_deep; i++) {
			os << '\t';
		}
		os << '}';
		return os;
	}
}