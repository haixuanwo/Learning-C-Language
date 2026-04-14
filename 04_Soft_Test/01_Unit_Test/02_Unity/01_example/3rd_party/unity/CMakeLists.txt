cmake_minimum_required(VERSION 3.0)

project(Unity_test)

add_library(Unity STATIC unity.c)
add_library(Unity::Test ALIAS Unity)
target_include_directories(Unity INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
