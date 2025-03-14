cmake_minimum_required(VERSION 3.10)
project(VK_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(VK_test src/main.cpp src/graph.cpp)

add_compile_definitions(PROJECT_ROOT="${CMAKE_SOURCE_DIR}")
