cmake_minimum_required(VERSION 3.7)
project(cuhkszlib_cmake)

set(CMAKE_CXX_STANDARD 11)

INCLUDE_DIRECTORIES(include/)
LINK_DIRECTORIES(lib/)

set(SOURCE_FILES src/main.cpp)
add_executable(cuhkszlib_cmake ${SOURCE_FILES})
target_link_libraries(cuhkszlib_cmake cuhkszlib)