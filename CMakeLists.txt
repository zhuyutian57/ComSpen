cmake_minimum_required(VERSION 3.16.0)

project(ComSpen)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(COMSPEN_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# include z3 into the project
find_package(Z3 REQUIRED CONFIG)

add_subdirectory(src)