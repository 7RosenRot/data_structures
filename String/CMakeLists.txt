cmake_minimum_required(VERSION 4.2)
set(This String)

project(${This} CXX)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REAUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers
  workspace/include/String.hpp
)
set(Sources
  workspace/source/String.cpp
)

add_library(${This} STATIC 
  ${Sources}
  ${Headers}
)

target_include_directories(${This} PUBLIC
  workspace/include
)

add_subdirectory(tests)