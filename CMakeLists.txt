cmake_minimum_required(VERSION 3.14)
project(Piscine-42)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
# set for C 
set(CMAKE_C_STANDARD 99)

enable_testing() # enables testing

add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

add_executable(test_return_one test_return_one.cpp return_one.c) # add this executable

target_link_libraries(test_return_one PRIVATE gtest) # link google test to this executable

include(GoogleTest)
gtest_discover_tests(test_return_one) # discover tests for this executable

# Generate test results in XML format
set(CTEST_OUTPUT_ON_FAILURE TRUE)
set(CTEST_XML_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Testing/")

include(CTest)
