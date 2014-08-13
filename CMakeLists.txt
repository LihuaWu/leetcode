cmake_minimum_required(VERSION 2.6)

project(leetcode)

include_directories(".")

add_executable(climbStairs climbStairs.cc)

add_library(listnode SHARED ListNode.cc)

add_executable(listTest listTest.cc)

target_link_libraries(listTest gtest)

target_link_libraries(climbStairs gtest)

install(TARGETS climbStairs DESTINATION bin)



