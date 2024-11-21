cmake_minimum_required(VERSION 3.1)

project(step5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(MyMath)

add_executable(main main.cpp)

target_link_libraries(main PUBLIC mymath)

# installation
install(TARGETS main DESTINATION bin)