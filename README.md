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
### 解析接口&输出接口
>创建一个JSON_value对象，通过其解析器返回解析出来的JSON树  
>>:( 不知道怎么解决，value的this不能换成对应类型的指针  
>>:( 所以这个内存没有释放也不知道怎么搞

	MyJSON::JSON_value* JSON_value::Parser(std::stringstream&);
	MyJSON::JSON_value* JSON_value::Parser(std::fstream&);

		using namespace MyJSON;
		//解析json
		JSON_value Myparser;	//just a parser
		JSON_value* JSON = Myparser->Parser(yourStream);
		
		
		JSON->print(ofile);	//std::ofstream ofile
		......			//do somthing with JSON such as below

>*每个JSON_\* 对象都有相应的Parser和Print（JSON_value除外，那个不能print）*  

	virtual std::ostream& JSON_value::Print(std::ostream& os) = 0;
### 调用接口
>***MyJSON Type***  

	enum JSONTYPE{Jerror = -1, Jinitial, Jobject, Jarray,Jstring, Jnumber, Jbool, Jnull};
>**object**  

	JSON_object Myobject
		Get_type() == Jobject;
		Get_size()		//number of pairs in the Myobject
		Myobject[key]

		Insert(key, value);

>**array**  

	JSON_array Myarray
		Get_type() == Jarray;
		Get_size()		//number of values in the Myarray;
		Myarray[index]

		Insert(index, value);		//index in range(0,size + 1)

>**string**  

	JSON_string Mystring
		Get_type() == Jstring;
		Get_value()		//a string in Mystring

		Set_value(std::string);

>**number**  

	JSON_number Mynumber
		Get_type() == Jnumber;
		/*for Get_value()
			return type is std::variant<int64_t, double, std::string>
			use auto to get the value
			if the value is out of range, return type is std::string
		*/
		Get_value()
		Get_value_string()		//return the value with string
		Get_value_type()		//return the typename of value

		//	it will return false when the string is invalid for number
		Set_value(std::string)

>**bool**  

	JSON_bool Mybool
		Get_type() == Jbool;
		Get_value()		//you know what it mean

		Set_value(bool)

>**null**  

	JSON_null Mynull
		Get_type() == Jnull;
		//and you can do nothing