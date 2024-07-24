# JSON解析器软件设计文档

## 背景
> JSON是一种轻量级数据交换格式， 被广泛应用于RESTful和各种RPC应用中。  
制作一个简易的JSON解析器便于对json类型的字串和文件做轻量便捷解析和处理

+ 基本功能
	- 实现使用递归下降解析器
    - 基于C++基本类型和STL容器，类型化JSON
		>object，array，int，bool，null和string
    - 解析std::istream为上述JSON类型
    - 将JSON类型序列化为std::ostream
    - 基于Google Test开发unittest
+ 扩展功能
    - 支持类似XML SAX的流式解析接口。
    - 支持UNICODE编码。



 
---
## 接口设计
### 解析接口&输出接口
>创建一个JSON_Value对象，通过其解析器返回解析出来的JSON树  
>>*返回一个智能指针*

	std::shared_ptr<MyJSON::JSON_Value> JSON_Value::parser(std::stringstream&);
	std::shared_ptr<MyJSON::JSON_Value> JSON_Value::parser(std::fstream&);
>
	using namespace MyJSON;
	//解析json
	JSON_Value Myparser
	std::shared_ptr<JSON_Value> JS = MyParser.parser(yourStream);
	//输出json
	JS->print(your ofstream);	// or std::cout

>*每个JSON_\* 对象都有相应的parser和print（JSON_Value除外，那个不能print）*  

	virtual std::ostream& JSON_Value::print(std::ostream& os);

### 调用接口
>***MyJSON Type***  

	enum JSON_Type
	{
		JERROR = -1,
		JINITIAL,
		JOBJECT,
		JARRAY,
		JSTRING,
		JNUMBER,
		JBOOL,
		JNULL
	};
>**object**  

	std::shared_ptr<JSON_Object> Myobject = JS->get_obj();

	get_type() == JOBJECT;
	get_size()		//number of pairs in the Myobject

	Myobject[key]	//a shared_ptr<JSON_Value>, key's sample: "name"

	insert(key, value);

>**array**  

	std::shared_ptr<JSON_Array> Myarray = JS->get_arr();

	get_type() == Jarray;
	get_size()		//number of values in the Myarray;

	Myarray[index]	//a shared_ptr<JSON_Value>

	insert(index, value);		//index in range(0,size + 1)

>**string**  

	std::shared_ptr<JSON_String> Mystring = JS->get_str();

	get_type() == Jstring;
	get_value()		//the json style string in Mystring

	set_value(std::string);
	/*
		string in json is like "\"abcdefg\""
		string in other is like "abcdefg"
		so there is a sample below:
	*/
	Mystring->set_value("abc123!");
	Mystring->get_value() == "\"abc123!\""	//true

>**number**  

	std::shared_ptr<JSON_Number> Mynumber = JS-get_num();

	get_type() == Jnumber;
	/*for Get_value()
		return type is std::variant<int64_t, double, std::string>
		use auto to get the value
		if the value is out of range, return type is std::string*/
	get_value()
	get_value_string()		//return the value with string
	get_value_type()		//return the typename of value

	//	it will return false when the string is invalid for number
	set_value(std::string)

>**bool**  

	std::shared_ptr<JSON_Bool> Mybool = JS->get_boo();

	get_type() == Jbool;
	get_value()		//return true o false

	set_value(bool)

>**null**  

	std::shared_ptr<JSON_NULL> Mynull = JS->get_nul();

	get_type() == Jnull;
	//and you can do nothing