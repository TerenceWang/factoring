cmake_minimum_required(VERSION 3.6)
project(factoring)
#INCLUDE_DIRECTORIES(include)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

add_executable(factoring ${SOURCE_FILES})