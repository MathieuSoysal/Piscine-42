cmake_minimum_required(VERSION 3.14)
project(Piscine-42)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
# set for C 
set(CMAKE_C_STANDARD 99)

# Setting compiler flags for coverage
if(CMAKE_COMPILER_IS_GNUCXX)
    message("Using GCC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message("Using Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
else()
    message(WARNING "Code coverage requires GCC or Clang. Compiler is ${CMAKE_CXX_COMPILER_ID}")
endif()

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

add_custom_target(coverage
                  COMMAND ${CMAKE_COMMAND} --build . --target test
                  COMMAND gcovr --root . --xml-pretty -o ${CMAKE_BINARY_DIR}/coverage.xml
                  DEPENDS test_return_one)

