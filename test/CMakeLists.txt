add_executable(listtest listTest)
target_link_libraries(listtest listnode gtest)
install (TARGETS listtest DESTINATION bin)


