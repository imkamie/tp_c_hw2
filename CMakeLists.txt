cmake_minimum_required(VERSION 3.16)

option(parallel "Build parallel version" OFF)

project(tp_c_hw2 C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(GCC_COVERAGE_COMPILE_FLAGS "-pthread")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS} -Wall -Wpedantic -Werror --coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -Wall -Wpedantic -Werror --coverage")

add_library(config STATIC project/src/config.c)
target_include_directories(config PUBLIC project/include)

add_library(fill_array STATIC project/src/fill_array.c)
target_include_directories(fill_array PUBLIC project/include)

add_library(consistent STATIC project/src/prog.c)
target_include_directories(consistent PUBLIC project/include)
target_link_libraries(consistent PUBLIC config fill_array)

add_library(parallel SHARED project/src/prog_parallel.c)
target_include_directories(parallel PUBLIC project/include)
target_link_libraries(parallel PUBLIC config fill_array)

add_executable(tp_c_hw2 project/src/main.c)

if(parallel)
    target_link_libraries(tp_c_hw2 parallel consistent)
else()
    target_link_libraries(tp_c_hw2 parallel consistent)
endif(parallel)

find_package(GTest REQUIRED)
set(SOURCES tests/run_tests.cpp tests/fill_array_test.cpp tests/stress_test.cpp)
add_executable(runTests ${SOURCES})
target_link_libraries(runTests GTest::gtest consistent parallel)