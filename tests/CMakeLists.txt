cmake_minimum_required (VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

aux_source_directory(./ TESTS)
aux_source_directory(./random RANDOM_TESTS)
aux_source_directory(./math_functions MATH_FUNCTIONS_TESTS)
aux_source_directory(./network NETWORK_TESTS)
aux_source_directory(./json JSON_TESTS)

include_directories(../include)


add_executable(test_all ${TESTS} ${RANDOM_TESTS} ${MATH_FUNCTIONS_TESTS} ${NETWORK_TESTS} ${JSON_TESTS} )
target_link_libraries(test_all gtest gtest_main cuhkszlib)
