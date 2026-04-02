cmake_minimum_required(VERSION 4.2)
set(This Vector)

project(${This} CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers
  workspace/include/Allocator.hpp
  workspace/include/Vector.hpp
)

add_library(${This} INTERFACE)

target_include_directories(${This} INTERFACE 
  workspace/include
)

add_subdirectory(tests)