cmake_minimum_required(VERSION 3.5)
project(heapsort)


set(VENDOR_ROOT ../../vendors)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(${VENDOR_ROOT}/catch)

set(SOURCE_FILES main.cpp)
add_executable(heapsort ${SOURCE_FILES})
