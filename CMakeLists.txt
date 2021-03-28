cmake_minimum_required(VERSION 3.16)
project(tp_c_hw2 C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(GCC_COVERAGE_COMPILE_FLAGS "-pthread")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS} -Wall -Wpedantic -Werror --coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -Wall -Wpedantic -Werror --coverage")

add_library(consistent STATIC project/src/consistent.c project/src/config.c)
target_include_directories(consistent PUBLIC project/include)

add_library(parallel SHARED project/src/parallel.c project/src/config.c)
target_include_directories(parallel PUBLIC project/include)

add_executable(tp_c_hw2 project/src/main.c)
target_link_libraries(tp_c_hw2 consistent parallel)

#find_package(GTest REQUIRED)
#set(SOURCES tests/run_tests.cpp tests/test_allocation.cpp tests/test_print.cpp tests/test_push.cpp tests/test_resize.cpp tests/test_sort.cpp tests/test_values.cpp)
#add_executable(runTests ${SOURCES})
#target_link_libraries(runTests GTest::gtest utils)