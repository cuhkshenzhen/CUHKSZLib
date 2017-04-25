cmake_minimum_required (VERSION 2.8)

project (cuhksz-cpp-lib)


if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W4 -wd4244 -wd4267 -wd4800 -wd4068")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Zi -Od")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Ox")
  add_definitions(-DUNICODE -D_UNICODE)
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wfloat-equal -std=c++11")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
endif()

aux_source_directory(./src/random RANDOM_SRC)
aux_source_directory(./src/math_utils MATHUTILS_SRC)
aux_source_directory(./src/json JSON_SRC)
aux_source_directory(./src/network NETWORK_SRC)
aux_source_directory(./src/graph GRAPH_SRC)
aux_source_directory(./src/geometry GEOMETRY_SRC)
aux_source_directory(./src/base64 BASE64_SRC)
aux_source_directory(./src/algorithm ALGORITHM_SRC)
aux_source_directory(./src/string_utils STRINGUTILS_SRC)
aux_source_directory(./src/utils UTILS_SRC)


include_directories(./src/include)
add_library(cuhkszlib STATIC ${RANDOM_SRC} ${MATHUTILS_SRC} ${JSON_SRC} ${NETWORK_SRC} ${GRAPH_SRC} ${GEOMETRY_SRC} ${BASE64_SRC} ${ALGORITHM_SRC} ${STRINGUTILS_SRC} ${UTILS_SRC})

option(TESTING "Enable testing with googletest" ON) # TODO off if release version
option(SAMPLES "Compile samples" ON)


if(TESTING)
  enable_testing()

  option(BUILD_GTEST "Builds the googletest subproject" ON)
  option(BUILD_GMOCK "Builds the googlemock subproject" OFF)
  if(MSVC)
    option(BUILD_SHARED_LIBS "Build shared libraries (DLLs)." ON)
  endif()
  add_subdirectory(./external/gtest/)

  include_directories(./external/gtest/googletest/include)
  add_subdirectory(./tests)
  add_test (NAME TestAll COMMAND test_all)
endif()

if(SAMPLES)
  add_subdirectory(./samples)
endif()
