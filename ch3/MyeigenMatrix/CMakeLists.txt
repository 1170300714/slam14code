cmake_minimum_required(VERSION 2.6)
project(myeigenmatrix)

add_executable(myeigenmatrix main.cpp)

install(TARGETS myeigenmatrix RUNTIME DESTINATION bin)
include_directories( "/usr/include/eigen3" )