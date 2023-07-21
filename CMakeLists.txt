cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(note)

# 设置 C++ 标准为 C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加可执行文件，并指定源文件
add_executable(myprogram main.cpp file.cpp)

# 添加头文件搜索路径
target_include_directories(myprogram PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 查找并链接所需的库文件
find_package(Threads REQUIRED)
target_link_libraries(myprogram PRIVATE Threads::Threads)