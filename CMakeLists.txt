cmake_minimum_required (VERSION 2.8)

project (cuhksz-cpp-lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

aux_source_directory(./src/random RANDOM_SRC)
aux_source_directory(./src/tests/random RANDOM_TESTS)
aux_source_directory(./src/tests/ TESTS)

include_directories(./src/include)
include_directories(./external/gtest/googletest/include)
link_directories(${CMAKE_BINARY_DIR}/)

add_subdirectory(./external/gtest/)
add_executable(test_all ${RANDOM_SRC} ${TESTS} ${RANDOM_TESTS})
target_link_libraries(test_all gtest gtest_main)
