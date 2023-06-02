# CMake最低版本要求
cmake_minimum_required (VERSION 2.8)
# 项目信息
project (Log_level)
# 制定生成目标
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")
add_executable(Log_level test.cpp log_level/log1.cpp buffer/buffer.cpp)
