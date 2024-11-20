cmake_minimum_required(VERSION 3.1)

project(Math)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

option(USE_MYMATH "Use MyMath" ON)

add_library(mymath MyMath.cpp)
target_link_libraries(mymath PUBLIC main_compiler_flags)

# Now that we've specified usage requirements for mymath
# We can safely remove our uses of the EXTRA_INCLUDES variable from the top-level CMakeLists.txt.
target_include_directories(mymath INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


if(USE_MYMATH)
    target_compile_definitions(mymath PRIVATE "USE_MYMATH")
endif()