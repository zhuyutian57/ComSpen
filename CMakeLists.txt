cmake_minimum_required(VERSION 3.16.0)

project(ComSpen)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(COMSPEN_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# include z3 into the project
find_package(Z3
  REQUIRED
  CONFIG
  # `NO_DEFAULT_PATH` is set so that -DZ3_DIR has to be passed to find Z3.
  # This should prevent us from accidentally picking up an installed
  # copy of Z3. This is here to benefit Z3's build system when building
  # this project. When making your own project you probably shouldn't
  # use this option.
  NO_DEFAULT_PATH
)
message(STATUS "The version of z3 is ${Z3_VERSION_STRING}")
message(STATUS "Paths of z3: ${Z3_DIR} ${Z3_CXX_INCLUDE_DIRS}")

add_subdirectory(src)