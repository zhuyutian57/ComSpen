cmake_minimum_required(VERSION 3.16.0)

project(ComSpen)

set(CMAKE_CXX_STANDARD 14)

# include z3 into the project
find_package(Z3 REQUIRED CONFIG)

find_package(smt2z3 REQUIRED)

add_executable(cpp_example example.cpp)
target_link_libraries(cpp_example ComSpen::smt2z3 ${Z3_LIBRARIES})