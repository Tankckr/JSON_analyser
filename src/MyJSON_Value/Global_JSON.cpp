#include"Global_JSON.h"
#include"JSON_Value.h"

namespace MyJSON
{
	/*----------非成员函数定义----------*/

	// std::ostream& operator<< (std::ostream& os, std::shared_ptr<JSON_Value>& v)
	// {
	// 	if (v->get_type() != JINITIAL) {
	// 		return v->print(os);
	// 	} else {
	// 		os << "Error, can not print void JSON\n";
	// 		return os;
	// 	}
	// }
	std::string type_string(JSON_Type& t)
	{
		switch (t) {
		case JINITIAL:
			return "JINITIAL";
		case JOBJECT:
			return "JOBJECT";
		case JARRAY:
			return "JARRAY";
		case JSTRING:
			return "JSTRING";
		case JNUMBER:
			return "JNUMBER";
		case JBOOL:
			return "JBOOL";
		case JNULL:
			return "JNULL";
		default:
			return "UNKNOWN";
		}
	}
}