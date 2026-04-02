cmake_minimum_required(VERSION 3.20)
set(This StringTests)

project(${This} CXX)

set(Sources
  main.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
  String
)