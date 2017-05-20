cmake_minimum_required (VERSION 2.8)

aux_source_directory(./ TESTS)
aux_source_directory(./random RANDOM_TESTS)
aux_source_directory(./math_utils MATHUTILS_TESTS)
aux_source_directory(./network NETWORK_TESTS)
aux_source_directory(./json JSON_TESTS)
aux_source_directory(./containers CONTAINERS_TESTS)
aux_source_directory(./base64 BASE64_TESTS)
aux_source_directory(./string_utils STRING_UTILS_TESTS)
aux_source_directory(./algorithm ALGORITHM_TESTS)

add_executable(test_all ${TESTS} ${RANDOM_TESTS} ${MATHUTILS_TESTS} ${NETWORK_TESTS} ${JSON_TESTS} ${BASE64_TESTS} ${ALGORITHM_TESTS} ${STRING_UTILS_TESTS} ${CONTAINERS_TESTS})

target_link_libraries(test_all gtest gtest_main cuhkszlib)

if(MSVC)
  add_custom_command(
    TARGET test_all POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_BINARY_DIR}/../external/gtest/googletest/$<CONFIG>/gtest.dll
            ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/gtest.dll)
endif()
