# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (test)

set(CMAKE_CXX_STANDARD 17)

# 查找当前目录下的所有源文件
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(test ${DIR_SRCS})

# 链接库
target_link_libraries(test jsoncpp pthread)

# 指定编译参数
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -std=c++17")
