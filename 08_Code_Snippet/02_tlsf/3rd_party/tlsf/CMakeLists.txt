
cmake_minimum_required(VERSION 3.10)

project(tlsf)

file(GLOB_RECURSE SOURCES *.c)

add_library(tlsf STATIC ${SOURCES})
target_include_directories(tlsf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
