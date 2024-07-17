# JSON解析器软件设计文档

## 背景
> JSON是一种轻量级数据交换格式， 被广泛应用于RESTful和各种RPC应用中。  
制作一个简易的JSON解析器便于对json类型的字串和文件做轻量便捷解析和处理

+ 项目提出者：广州鼎甲计算机科技有限公司
+ 开发人员：陈锴瑞
+ 指导老师：娄永杰
+ 开发环境：
    - OS：Ubuntu20.04/22.04
    - 编辑器：VIM/VS code
    - 编译器：GCC(OS内置)
    - 构建：CMake
    - VCS：Git
+ 基本功能
	- 实现使用递归下降解析器
    - 基于C++基本类型和STL容器，类型化JSON
		>object，array，int，bool，null和string
    - 解析std::istream为上述JSON类型
    - 将JSON类型序列化为std::ostream
    - 基于Google Test开发unittest
+ 扩展功能(可选)
    - 支持类似XML SAX的流式解析接口。
    - 支持UNICODE编码。

### 参考资料
*JSON区*  
[JSON中国|JSON中文网](https://www.json.org.cn/)  
[RFC4627（JSON规范）](https://www.rfc-editor.org/rfc/rfc4627.txt)    
*参考区*  
[简易的 C++ JSON解析器](https://www.cnblogs.com/xqk0225/articles/18019385)  
[编译原理：递归下降分析](https://moyangsensei.github.io/2019/04/21/%E7%BC%96%E8%AF%91%E5%8E%9F%E7%90%86%EF%BC%9A%E9%80%92%E5%BD%92%E4%B8%8B%E9%99%8D%E5%88%86%E6%9E%90/)  
*文档区*  
[一个Json解析库的设计和实现](https://blog.csdn.net/zhaojia92/article/details/123969667)  
[书栈网《概要设计说明书》](https://www.bookstack.cn/read/DocumentTemplate/Architectural-Design-Specification.md)

---
## 设计思路
### 数据输入流程
![json输入流程](./pic_src/parser_file.png)

### 数据结构
	class JSON_value						//基类

	class JSON_object: public JSON_value	//object类型数 据通过std::unordered_map<JSON_value>实现
	class JSON_array: public JSON_value	//array类型数据 通过std::vector<JSON_value>实现
	class JSON_string: public JSON_value	//string类型数据
	class JSON_number: public JSON_value	//number类型数据
	class JSON_bool: public JSON_value	//true,false两个bool型
	class JSON_null: public JSON_value	//null类型
	class JSON_error: public JSON_value	//报错类型

---
## 实现方法
### 词法分析
#### json的数据类型
|	值名称	|	表达式	|	 描述	|
|----------|-------------|-----------|
| string	| ^"[^"]*" | 字符串， 两头包着"" |
| number	| ^-?([0]\|[1-9][0-9]\*)(.[0-9]{1,})?([e\|E][+\|-]?[1-9][0-9]*)? | 整形浮点 |
| bool		| (true)\|(false) | 就true和false |
| null		| (null)| 就null |
| object	| ^\\{(string:value)\*} | 由'{'和'}'包着的 若干个用','分隔的string:value对 |
| array		| ^\[(value)*] | 由'['和']'包着的 若干个用','分隔的value |

#### 词法分析流程图
***所有json的数据类型都是一种value***  
![value解析器](./pic_src/parser_value.png)

***数字通过正则表达式贪心匹配再转为值存储在对象中***  
![number解析器](./pic_src/parser_number.png)

***object解析器 & array解析器***  
![object解析器 & array解析器](./pic_src/parser_obj&array.png)

### 语法分析
***使用递归下降解析器***  
***JSON文法***  
|   名称    |   符号    |   名称    |   符号    |
|----------|-----------|----------|----------|
|   object  |   O		|	member  |   M   |
|   array   |   A		|	string  |   s   |
|   value   |   V		|	number  |   n   |
| objectNode|   ON		|	bool    |   b   |
| arrayNode |   AN		|	null    |   u   |

	S -> S'
	S'-> O|A		//json文件从object或者array开始
	O -> {ON}
	A -> [AN]
	ON-> M,ON|M|ε		//object列表项可以是一个或多个或者空
	AN-> V,AN|V|ε		//array列表项同理
	M -> s:V
	V -> O|A|s|n|b|u
>其实json格式解析也可以看作一个大的object或者array词法分析

#### json解析主流程
![json文件主流程](./pic_src/parser_json_file.png)

---
## 接口设计
### 解析接口&输出接口
>创建一个JSON_value对象，通过其解析器返回解析出来的JSON树  
>>（不知道怎么解决把this换成对应value的指针的问题）  
>>:( 所以禁止实例化JSON_value对象（不知道可不可以通过代码实现限制）

	MyJSON::JSON_value* JSON_value::Parser(std::stringstream&);
	MyJSON::JSON_value* JSON_value::Parser(std::fstream&);

		using namespace MyJSON;
		//解析json
		JSON_value* Myparser;
		Myparser = Myparser->Parser(yourStream);
>*每个JSON_\* 都有相应的Parser和Print（JSON_value除外，那个不能print）*  

	virtual std::ostream& JSON_value::Print(std::ostream& os) = 0;
### 调用接口
>**MyJSON Type**  

	enum JSONTYPE{Jerror = -1, Jinitial, Jobject, Jarray,Jstring, Jnumber, Jbool, Jnull};
>object  

	JSON_object Myobject
		Get_type() == Jobject;
		Get_size()		//number of pairs in the Myobject
		Myobject[key]

		Insert(key, value);

>array  

	JSON_array Myarray
		Get_type() == Jarray;
		Get_size()		//number of values in the Myarray;
		Myarray[index]

		Insert(index, value);		//index in range(0,size + 1)

>string  

	JSON_string Mystring
		Get_type() == Jstring;
		Get_value()		//a string in Mystring

		Set_value(std::string);

>number  

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

>bool  

	JSON_bool Mybool
		Get_type() == Jbool;
		Get_value()		//you know what it mean

		Set_value(bool)

>null  

	JSON_null Mynull
		Get_type() == Jnull;
		//and you can do nothing