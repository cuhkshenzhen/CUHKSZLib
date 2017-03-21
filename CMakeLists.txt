cmake_minimum_required (VERSION 2.8)

project (cuhksz-cpp-lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wfloat-equal -std=c++11")

aux_source_directory(./src/random RANDOM_SRC)
aux_source_directory(./src/math MATH_SRC)
aux_source_directory(./src/json JSON_SRC)
aux_source_directory(./src/network NETWORK_SRC)


include_directories(./src/include)
add_library(cuhkszlib STATIC ${RANDOM_SRC} ${MATH_SRC} ${JSON_SRC} ${NETWORK_SRC})


# TODO: Only enable testing when certain variable is set
enable_testing ()

option(BUILD_GTEST "Builds the googletest subproject" ON)
option(BUILD_GMOCK "Builds the googlemock subproject" OFF)
add_subdirectory(./external/gtest/)

include_directories(./external/gtest/googletest/include)
add_subdirectory(./tests)
add_test (NAME TestAll COMMAND test_all)
