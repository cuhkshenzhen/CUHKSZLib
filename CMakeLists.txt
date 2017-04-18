cmake_minimum_required (VERSION 2.8)

project (cuhksz-cpp-lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wfloat-equal -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

aux_source_directory(./src/random RANDOM_SRC)
aux_source_directory(./src/math_utils MATHUTILS_SRC)
aux_source_directory(./src/json JSON_SRC)
aux_source_directory(./src/network NETWORK_SRC)
aux_source_directory(./src/graph GRAPH_SRC)
aux_source_directory(./src/geometry GEOMETRY_SRC)
aux_source_directory(./src/base64 BASE64_SRC)


include_directories(./src/include)
add_library(cuhkszlib STATIC ${RANDOM_SRC} ${MATHUTILS_SRC} ${JSON_SRC} ${NETWORK_SRC} ${GRAPH_SRC} ${GEOMETRY_SRC} ${BASE64_SRC} src/zip/zip_functions.cpp src/include/zip/zip_functions.h src/string/string_functions.cpp src/include/string/string_functions.h)

option(TESTING "Enable testing with googletest" ON) # TODO off if release version

if(TESTING)
  enable_testing ()

  option(BUILD_GTEST "Builds the googletest subproject" ON)
  option(BUILD_GMOCK "Builds the googlemock subproject" OFF)
  add_subdirectory(./external/gtest/)

  include_directories(./external/gtest/googletest/include)
  add_subdirectory(./tests)
  add_test (NAME TestAll COMMAND test_all)
endif()
