cmake_minimum_required (VERSION 2.8)

aux_source_directory(./ TESTS)
aux_source_directory(./random RANDOM_TESTS)
aux_source_directory(./math MATH_TESTS)
aux_source_directory(./network NETWORK_TESTS)
aux_source_directory(./json JSON_TESTS)
aux_source_directory(./containers CONTAINERS_TESTS)

include_directories(../src/include)
include_directories(../external/gtest/googletest/include)


add_executable(test_containers ${CONTAINERS_TESTS} )
target_link_libraries(test_containers gtest gtest_main cuhkszlib)
