#include"SAJ.h"
#include"MyJSON.h"

namespace MyJSON
{
	void parse_to_SAJ(std::stringstream& ss, SAJ_Processor& p)
	{
		p.parse_start();
		if(!SAJ_Parser::SAJ_value(ss, p)) {
			return;
		}
		p.parse_end();

	}
	bool SAJ_Parser::SAJ_value(std::stringstream& ss, SAJ_Processor& p)
	{
		ignore_blank(ss);
		char ch = ss.peek();
		if (ch == '{') {
			return SAJ_object(ss, p);
		}
		if (ch == '[') {
			return SAJ_array(ss, p);
		}
		if (ch == '"') {
			return SAJ_string(ss, p);
		}
		if (ch == '-' || (ch <= '9' && ch >= '0')) {
			return SAJ_number(ss, p);
		}
		if (ch == 't' || ch == 'f') {
			return SAJ_bool(ss, p);
		}
		if (ch == 'n') {
			return SAJ_null(ss, p);
		}
		//else
		p.error(666, ""+ss.peek(), syntax_error_unknown_type);
		return false;
	}

	bool SAJ_Parser::SAJ_object(std::stringstream& ss, SAJ_Processor& p)
	{
		p.object_start();
		if (ss.peek() != '{') {
			p.error(error_line,
					"_"+ss.peek(),
					syntax_error_object + " Expect:'{'");
			return false;
		}ss.ignore();
		ignore_blank(ss);
		if (ss.peek() == '}') {	//{}
			ss.ignore();
			p.object_end();
			return true;
		}
		while (ss.peek() != EOF) {
			/*---key---*/
			std::shared_ptr<JSON_String> pS = std::make_shared<JSON_String>();
			pS = pS->parser(ss)->get_str();
			if (pS->get_type() == JERROR) {
				p.error(error_line, ""+ss.peek(), syntax_error_string);
				return false;
			}
			p.object_key(pS->get_value());
			/*---:---*/
			ignore_blank(ss);
			if (ss.peek() != ':') {
				p.error(error_line,
						"_"+ss.peek(),
						syntax_error_object + " Expect: ':'");
				return false;
			}ss.ignore();
			/*---value---*/
			if (!SAJ_value(ss, p)) {
				return false;
			}
			/*---next---*/
			ignore_blank(ss);
			if (ss.peek() == ',') {
				ss.ignore();
				continue;
			} else if (ss.peek() == '}') {
				ss.ignore();
				p.object_end();
				return true;
			} else {
				p.error(error_line, "_"+ss.peek(),
						syntax_error_object + " Expect: ','");
				return false;
			}
		}
		p.error(error_line, ""+ss.str().back(), error_broken_file);
		return false;
	}

	bool SAJ_Parser::SAJ_array(std::stringstream& ss, SAJ_Processor& p)
	{
		p.array_start();
		if (ss.peek() != '[') {
			p.error(error_line,
					"_"+ss.peek(),
					syntax_error_array + " Expect: '['");
			return false;
		}ss.ignore();
		ignore_blank(ss);
		if (ss.peek() == ']') {
			ss.ignore();
			p.array_end();
			return true;
		}
		while (ss.peek() != EOF) {
			/*---value---*/
			if (!SAJ_value(ss, p)) {
				return false;
			}
			/*---next---*/
			ignore_blank(ss);
			if (ss.peek() == ',') {
				ss.ignore();
				continue;
			} else if (ss.peek() == ']') {
				ss.ignore();
				p.array_end();
				return true;
			} else {
				p.error(error_line, "_"+ss.peek(),
						syntax_error_array + " Expect: ','");
				return false;
			}
		}
		p.error(error_line, ""+ss.str().back(), error_broken_file);
		return false;
	}

	bool SAJ_Parser::SAJ_string(std::stringstream& ss, SAJ_Processor& p)
	{
		std::shared_ptr<JSON_String> pS = std::make_shared<JSON_String>();
		pS = pS->parser(ss)->get_str();
		if (pS->get_type() == JERROR) {
			std::string error_code;
			getline(ss, error_code);
			p.error(error_line, error_code, syntax_error_string);
			return false;
		}
		p.string(pS->get_value());
		return true;
	}

	bool SAJ_Parser::SAJ_number(std::stringstream& ss, SAJ_Processor& p)
	{
		std::shared_ptr<JSON_Number> pN = std::make_shared<JSON_Number>();
		pN = pN->parser(ss)->get_num();
		if (pN->get_type() == JERROR) {
			std::string error_code;
			getline(ss, error_code);
			p.error(error_line, error_code, syntax_error_number);
			return false;
		}
		if (pN->get_value_type() == "int64") {
			p.number_int(std::get<int64_t>(pN->get_value()));
			return true;
		} else if (pN->get_value_type() == "double") {
			p.number_double(std::get<double>(pN->get_value()));
			return true;
		} else if (pN->get_value_type() == "string") {
			p.number_out_of_range(std::get<std::string>(pN->get_value()));
		}
		p.error(error_line, ""+ss.peek(), "Unknown Error");
		return false;
	}

	bool SAJ_Parser::SAJ_bool(std::stringstream& ss, SAJ_Processor& p)
	{
		std::shared_ptr<JSON_Bool> pB = std::make_shared<JSON_Bool>();
		pB = pB->parser(ss)->get_boo();
		if (pB->get_type() == JERROR) {
			std::string error_code;
			getline(ss, error_code);
			p.error(error_line, error_code, syntax_error_unknown_type);
			return false;
		}
		p.boolean(pB->get_value());
		return true;
	}

	bool SAJ_Parser::SAJ_null(std::stringstream& ss, SAJ_Processor& p)
	{
		std::shared_ptr<JSON_NULL> pN = std::make_shared<JSON_NULL>();
		pN = pN->parser(ss)->get_nul();
		if (pN->get_type() == JERROR) {
			std::string error_code;
			getline(ss, error_code);
			p.error(error_line, error_code, syntax_error_unknown_type);
			return false;
		}
		p.null();
		return true;
	}
}