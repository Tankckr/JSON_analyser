# JSON_analyser
## 鼎甲命题项目 JSON解析器
#### 背景
JSON是一种轻量级数据交换格式， 被广泛应用于RESTful和各种RPC应用中。

#### 开发环境
    OS：Ubuntu20.04/22.04
    编辑器：VIM/VS code
    编译器：GCC(OS内置)
    构建：C Make
    VCS：Git

#### 基本要求
    实现使用递归下降解析器
    C++17STL， 不能使用Boost等任何第三方库。
    基于C++基本类型和STL容器， 类型化JSON object， array， int， real和string
    解析std：：istream为上述JSON类型。
    将JSON类型序列化为std：：ostream
    基于Google Test开发unittest
    撰写开发文档，包括：
        定义开发阶段和成果(Merge Request)
        概要设计
        详细设计

#### 扩展要求(可选)
    支持类似XML SAX的流式解析接口。
    支持UNICODE编码。