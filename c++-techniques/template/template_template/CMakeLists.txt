cmake_minimum_required(VERSION 3.5)
project(template_template)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp)
add_executable(template_template ${SOURCE_FILES})