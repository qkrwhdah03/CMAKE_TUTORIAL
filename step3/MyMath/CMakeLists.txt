cmake_minimum_required(VERSION 3.1)

project(Math)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

option(USE_MYMATH "Use MyMath" ON)

add_library(mymath MyMath.cpp)

if(USE_MYMATH)
    target_compile_definitions(mymath PRIVATE "USE_MYMATH")
endif()