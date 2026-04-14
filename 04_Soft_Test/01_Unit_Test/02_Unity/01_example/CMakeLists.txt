
cmake_minimum_required(VERSION 3.10)

# Set the project name
project (unity_test)

# set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# add the CMakeFile that defines catch2
add_subdirectory(3rd_party/unity)

file(GLOB_RECURSE SOURCES src/*.c)

add_executable(main main.c ${SOURCES})

target_include_directories(main
    PUBLIC
        ${PROJECT_SOURCE_DIR}/src
)

#############################################
# Unit tests

# enable CTest testing
enable_testing()

file(GLOB_RECURSE TEST_SOURCES unit_test/*.c)

# Add a testing executable
add_executable(unit_test ${SOURCES} ${TEST_SOURCES})

target_link_libraries(unit_test
    Unity::Test
)

target_include_directories(unit_test
    PUBLIC
        ${PROJECT_SOURCE_DIR}/src
)

add_test(test_all unit_test)
