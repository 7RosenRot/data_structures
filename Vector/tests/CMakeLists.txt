cmake_minimum_required(VERSION 4.2)
set(This VectorTests)

project(${This} CXX)

set(Sources
  main.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PRIVATE
  Vector
)