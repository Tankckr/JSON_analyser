# 测试用例的CMakeLists
# 关联test.cpp生成MyJSONTest

cmake_minimum_required(VERSION 3.5)
project(MyJSONTest)

# 指定使用 C++17 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# google test
# 查找GTest库
find_package(GTest REQUIRED)

# 包含GTest头文件目录
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}) # 包含当前源代码目录，以便找到MyJSON.h

# 创建可执行文件并链接
file(GLOB SOURCES "../src/MyJSON_Value/*.cpp")
add_executable(MyJSONTests ${SOURCES} ../test.cpp)
target_link_libraries(MyJSONTests ${GTEST_LIBRARIES} pthread)

# 添加测试
enable_testing()
add_test(NAME MyJSONTests COMMAND MyJSONTests)
