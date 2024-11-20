cmake_minimum_required(VERSION 3.1)

project(step4 VERSION 1.0)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(main_compiler_flags INTERFACE)
target_compile_features(main_compiler_flags INTERFACE cxx_std_11)


add_subdirectory(MyMath)

add_executable(main main.cpp)

#target_link_libraries(main PUBLIC mymath)
target_link_libraries(main PUBLIC mymath main_compiler_flags)

# We don't need to include directories in the top-level directory
# Since MyMath handle this
#target_include_directories(main PUBLIC "${PROJECT_SOURCE_DIR}/MyMath")