#指定运行此配置文件所需的 CMake 的最低版本；
cmake_minimum_required(VERSION 3.10)

#项目名
project(LuaDemo)

#C11
set(CMAKE_CXX_STANDARD 11)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(./lua DIR_SRCS)

add_executable(LuaDemo ${DIR_SRCS} main.cpp)


