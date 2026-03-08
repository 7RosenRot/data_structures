cmake_minimum_required(VERSION 3.8)
set(This LinkedListTests)

project(${This} CXX)

set(Sources
  main.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
  gtest_main
  LinkedList
)

include(GoogleTest)
gtest_discover_tests(${This})