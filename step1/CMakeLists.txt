# 1. Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.10) 

# 1. Set Project Name
#project(step1)

# 3. Set Project Name and Specify the project version
project(step1 VERSION 1.0)

# 2. Specify the c++ standard version 
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# 1. Add excutable main.exe 
add_executable(main main.cpp)

# 3. Cofigure File
configure_file(config.h.in config.h) # config.h will be made in $PROJECT_BINARY_DIR
target_include_directories(main PUBLIC ${PROJECT_BINARY_DIR})