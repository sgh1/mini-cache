cmake_minimum_required(VERSION 2.8)

project(cache)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -Wno-unused-parameter")

add_executable(cache main.cpp)
