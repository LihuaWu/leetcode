cmake_minimum_required(VERSION 2.6)

project(leetcode CXX)
include_directories(${PROJECT_SOURCE_DIR})
#message(STATUS "include dir: " ${PROJECT_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/leetcode)
#message(STATUS "include dir: " ${PROJECT_INCLUDE_DIR})
add_subdirectory(leetcode)
add_subdirectory(test)

set(EXECUTABLE_OUTPUT_PATH  $(PROJECT_BINARY_DIR)/bin)
set(LIBRARY_OUTPUT_PATH  $(PROJECT_BINARY_DIR)/lib)
