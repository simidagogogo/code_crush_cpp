cmake_minimum_required(VERSION 3.17)
project(code_crush_cpp)

include_directories(/Users/zhangda/CLionProjects/code_crush_cpp)
set(CMAKE_CXX_STANDARD 20)

add_executable(code_crush_cpp main.cpp p1000/Main.h p1000/Solution.h Scmp.h TestRunner.h p5152/Main.h p5152/Solution.h)