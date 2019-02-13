cmake_minimum_required(VERSION 2.8)

project(HelloNova_SLAM)

add_executable(useHello useHello.cpp)
add_library(libhello libHelloSLAM.cpp)
add_library(hello_shared SHARED libHelloSLAM.cpp)
#target_link_libraries( useHello hello_shared )
