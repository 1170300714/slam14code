cmake_minimum_required(VERSION 2.6)
project(linearequation)

include_directories( "/usr/include/eigen3" )

add_executable(linearequation main.cpp)

install(TARGETS linearequation RUNTIME DESTINATION bin)
