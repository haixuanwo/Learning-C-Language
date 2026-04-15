
cmake_minimum_required(VERSION 3.10)

project(Unity_test)

file(GLOB_RECURSE SOURCES *.c)

add_library(Unity STATIC ${SOURCES})
add_library(Unity::Test ALIAS Unity)

target_compile_options(Unity PUBLIC -DUNITY_FIXTURE_NO_EXTRAS)
target_include_directories(Unity PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
