cmake_minimum_required (VERSION 2.8)

project (cuhksz-cpp-lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

aux_source_directory(./src/random RANDOM_SRC)
aux_source_directory(./src/math MATH_SRC)


include_directories(./src/include)
add_library(cuhkszlib STATIC ${RANDOM_SRC} ${MATH_SRC})

# TODO: Only enable testing when certain variable is set
enable_testing ()
add_subdirectory(./tests)

option(BUILD_GTEST "Builds the googletest subproject" ON)
option(BUILD_GMOCK "Builds the googlemock subproject" OFF)
add_subdirectory(./external/gtest/)
add_test (NAME TestAll COMMAND test_all)
