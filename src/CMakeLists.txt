include_directories("${COMSPEN_SOURCE_DIR}/include/")

file(GLOB_RECURSE COMSPEN_HEADERS "${COMSPEN_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE COMSPEN_SRCS "${COMSPEN_SOURCE_DIR}/src/*.cpp")

# message(STATUS ${COMSPEN_HEADERS})
# message(STATUS ${COMSPEN_SRCS})

add_library(
  smt2z3 SHARED ${COMSPEN_HEADERS} ${COMSPEN_SRCS}
)

add_executable(ComSpen main.cpp)
target_link_libraries(ComSpen smt2z3 ${Z3_LIBRARIES})

set (api_public_headers
  slah_api.h
)
foreach (header ${api_public_headers})
  set_property(TARGET smt2z3 APPEND PROPERTY
    PUBLIC_HEADER "${COMSPEN_SOURCE_DIR}/include/api/${header}")
endforeach()

target_include_directories(smt2z3 PUBLIC
  $<BUILD_INTERFACE:${COMSPEN_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  )

install(TARGETS ComSpen DESTINATION "${CMAKE_INSTALL_BINDIR}")
install(TARGETS smt2z3
  EXPORT smt2z3-targets
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
  )

install(EXPORT smt2z3-targets
  NAMESPACE ComSpen::
  FILE smt2z3-config.cmake
  DESTINATION lib/cmake/smt2z3
  )