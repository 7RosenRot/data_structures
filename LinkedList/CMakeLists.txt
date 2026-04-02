cmake_minimum_required(VERSION 3.10)
set(This LinkedList)

project(${This} CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(
  ${CMAKE_CURRENT_SOURCE_DIR}/../googletest
  ${CMAKE_CURRENT_BINARY_DIR}/googletest
)

set(Headers
  workspace/include/LinkedList.hpp
  workspace/include/Serialization.hpp
)

set(Sources
  workspace/source/LinkedList.cpp
  workspace/source/Serialization.cpp
)

add_library(${This} STATIC
  ${Headers}
  ${Sources}
)

target_include_directories(${This} PUBLIC
  workspace/include
)

add_subdirectory(tests)