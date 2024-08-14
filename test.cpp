#include <gtest/gtest.h>
#include <fstream>
#include "./src/MyJSON.h"
using namespace MyJSON;

JSON_Value val_parser;
JSON_Object obj_parser;
JSON_Array arr_parser;
JSON_String str_parser;
JSON_Number num_parser;
JSON_Bool boo_parser;
JSON_NULL nul_parser;
std::shared_ptr<JSON_Value> father;

int main(int argc, char **argv)
{
    // 分析gtest程序的命令行参数
    // testing::InitGoogleTest(&argc, argv);

    // 调用RUN_ALL_TESTS()运行所有测试用例
    // main函数返回RUN_ALL_TESTS()的运行结果
	// return RUN_ALL_TESTS();
	std::ifstream inputfile("/home/scutech/Desktop/codes/JSON_analyser"
							"/JSON_analyser/test_sample2.json");
	if (!inputfile.is_open()) {
		std::cerr << "Can not open\n";
		return -1;
	}
	JSON_Parser MyParser;
	std::shared_ptr<JSON_Value> root;
	root = MyParser.parse(inputfile);
	if (root == nullptr) {
		std::cerr << "Error!!!\n";
		MyParser.print_error();
		return -1;
	}
	std::cout << "Parse end\n";
	JSON_Printer MyPrinter;
	if (!MyPrinter.print(std::cout, *root.get())) {
		MyPrinter.print_error();
	}
}

// TEST(GetType_Test, EQ)
// {
//     EXPECT_EQ(JINITIAL, val_parser.get_type());
//     EXPECT_EQ(JOBJECT, obj_parser.get_type());
//     EXPECT_EQ(JARRAY, arr_parser.get_type());
//     EXPECT_EQ(JSTRING, str_parser.get_type());
//     EXPECT_EQ(JNUMBER, num_parser.get_type());
//     EXPECT_EQ(JBOOL, boo_parser.get_type());
// 	EXPECT_EQ(JNULL, nul_parser.get_type());
// }
// /*-----报错-----*/
// TEST(JSON_value, get_xxx)
// {
// 	EXPECT_THROW(val_parser.get_obj(), const char*);
// 	EXPECT_THROW(val_parser.get_arr(), const char*);
// 	EXPECT_THROW(val_parser.get_str(), const char*);
// 	EXPECT_THROW(val_parser.get_num(), const char*);
// 	EXPECT_THROW(val_parser.get_boo(), const char*);
// 	EXPECT_THROW(val_parser.get_nul(), const char*);
// }

// /*-----类函数-----*/
// TEST(JSON_object, parser)
// {
// 	std::stringstream ss;
// 	ss << "{\"key2\":123,\"key1\":\"v1\",\"key3\":false,\"key5\":[1,2,3]}";
// 	std::shared_ptr<JSON_Object> p = val_parser.parser(ss, father)->get_obj();
// 	std::cout << ss.str();
// 	p->print(std::cout);
// 	ASSERT_EQ(JOBJECT, p->get_type());
// 	EXPECT_EQ(p->get_size(), 4);
// 	EXPECT_EQ("v1", (*p)["key1"]->get_str()->get_value());
// 	EXPECT_EQ((*(*p)["key5"]->get_arr())[2]->get_num()->get_value_string(), "3");

// 	EXPECT_EQ(father, p->get_father());
// 	EXPECT_EQ(p, (*p)["key3"]->get_father());

// }
// TEST(JSON_object, ostream)
// {
// 	std::ifstream file("../test_sample2.json");
// 	if (file.is_open())
// 	{
// 		std::shared_ptr<JSON_Value> p = val_parser.parser(file, father);
// 		EXPECT_EQ(JOBJECT, p->get_type());
// 		p->print(std::cout);
// 	} else {
// 		std::cout << "cannot open\n";
// 	}
		
// }
// TEST(JSON_object, insert)
// {
// 	std::stringstream ss;
// 	ss << "{\"key1\":\"OHHHH\",\"ckey2\":12.3e2,\"key3\":true}{\"key1\":\"v1\",\"key2\":123}null";
// 	std::shared_ptr<JSON_Object> p = obj_parser.parser(ss, father)->get_obj();
// 	std::shared_ptr<JSON_Value> i = obj_parser.parser(ss, father);
// 	// p->print(std::cout);std::cout << '\n';
// 	// i->print(std::cout);std::cout << '\n';
// 	p->insert("key4", i);
// 	ASSERT_EQ(JOBJECT, (*p)["key4"]->get_type());
// 	EXPECT_EQ(i, (*p)["key4"]);
// 	std::shared_ptr<JSON_Object> k4 = (*p)["key4"]->get_obj();
// 	EXPECT_EQ(JNUMBER, (*k4)["key2"]->get_type());
// 	EXPECT_EQ(123, std::get<int64_t>((*k4)["key2"]->get_num()->get_value()));
// 	// p->print(std::cout);

// 	i = nul_parser.parser(ss, father);
// 	EXPECT_EQ(JNULL, i->get_type());
// 	EXPECT_NE(i, (*p)["key4"]);
// 	// p->print(std::cout);
// 	EXPECT_EQ((*p)["key4"], (*(*p)["key4"]->get_obj())["key1"]->get_father());
// }

// TEST(JSON_array, parser)
// {
// 	std::stringstream ss;
// 	ss << "[\"this is a string\", 9876.5432e-1, false, null, {}, [1, true,2, \"\xE8\x80\xB6\",3],[]]";
// 	std::shared_ptr<JSON_Array> p = arr_parser.parser(ss, father)->get_arr();
// 	p->print(std::cout);
// 	ASSERT_EQ(JARRAY, p->get_type());
// 	EXPECT_EQ(7, p->get_size());
// 	EXPECT_EQ(5, (*p)[5]->get_arr()->get_size());
// 	EXPECT_EQ(987.65432, std::get<double>((*p)[1]->get_num()->get_value()));
// 	EXPECT_EQ(true, (*(*p)[5]->get_arr())[1]->get_boo()->get_value());
// 	EXPECT_EQ("耶", (*(*p)[5]->get_arr())[3]->get_str()->get_value());
// 	EXPECT_EQ(p, (*p)[3]->get_father());
// 	EXPECT_EQ((*p)[5], (*(*p)[5]->get_arr())[4]->get_father());
// }
// TEST(JSON_array, insert)
// {
// 	std::stringstream ss;
// 	ss << "[1,2,3,5,6,8,\"9\"]";
// 	std::shared_ptr<JSON_Array> p = arr_parser.parser(ss, father)->get_arr();
// 	p->print(std::cout);
// 	std::shared_ptr<JSON_String> s4(new JSON_String());
// 	s4->set_father(father);
// 	s4->set_value("4");
// 	p->insert(3, s4);
// 	s4 = (*p)[7]->get_str();
// 	s4->set_value("999");
// 	p->print(std::cout);
// 	EXPECT_EQ(p, (*p)[3]->get_father());
// }

// TEST(JSON_string, all)
// {
// 	std::stringstream ss;
// 	ss << "\"wi298d9wqh)+*(#^@!~epa{}.jkogq7 qgbc\"";
// 	std::shared_ptr<JSON_String> p = str_parser.parser(ss, father)->get_str();

// 	ASSERT_EQ(JSTRING, p->get_type());
// 	EXPECT_EQ("wi298d9wqh)+*(#^@!~epa{}.jkogq7 qgbc", p->get_value());
// 	p->set_value("Hello GTEST  orz");
// 	EXPECT_EQ("Hello GTEST  orz", p->get_value());
// 	EXPECT_EQ(p->get_father(), father);
// }
// TEST(JSON_number, all)
// {
// 	std::stringstream ss;
// 	ss << "123456789.987654321";
// 	std::shared_ptr<JSON_Number> p = num_parser.parser(ss, father)->get_num();

// 	ASSERT_EQ(JNUMBER, p->get_type());
// 	//double
// 	EXPECT_EQ("double", p->get_value_type());
// 	EXPECT_EQ("123456789.987654321", p->get_value_string());
// 	EXPECT_EQ(123456789.987654321, std::get<double>(p->get_value()));
// 	//string
// 	p->set_value("1234.5678e+910");
// 	EXPECT_EQ("string", p->get_value_type());
// 	EXPECT_EQ("1234.5678e+910", p->get_value_string());
// 	EXPECT_EQ("1234.5678e+910", std::get<std::string>(p->get_value()));
// 	//int
// 	p->set_value("1234567890987654321");
// 	EXPECT_EQ("int64", p->get_value_type());
// 	EXPECT_EQ("1234567890987654321", p->get_value_string());
// 	EXPECT_EQ(1234567890987654321, std::get<int64_t>(p->get_value()));

// 	EXPECT_EQ(p->get_father(), father);
// }
// TEST(JSON_bool, all)
// {
// 	std::stringstream ss;
// 	ss << "truefalse";
// 	std::shared_ptr<JSON_Bool> p = boo_parser.parser(ss, father)->get_boo();

// 	ASSERT_EQ(JBOOL, p->get_type());
// 	EXPECT_EQ(true, p->get_value());

// 	p = boo_parser.parser(ss, father)->get_boo();
// 	ASSERT_EQ(JBOOL, p->get_type());
// 	EXPECT_EQ(false, p->get_value());

// 	EXPECT_EQ(p->get_father(), father);
// }
// TEST(JSON_null, all)
// {
// 	std::stringstream ss;
// 	ss << "null298rw";
// 	std::shared_ptr<JSON_NULL> p = nul_parser.parser(ss, father)->get_nul();
// 	ASSERT_EQ(JNULL, p->get_type());

// 	EXPECT_EQ(p->get_father(), father);
// }