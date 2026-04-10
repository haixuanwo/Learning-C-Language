cmake_minimum_required(VERSION 3.10)

# Set the project name
project (google_test_example)


find_package(GTest REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.cc)

add_executable(main main.cc ${SOURCES})
target_include_directories(main
    PUBLIC
        ${PROJECT_SOURCE_DIR}/src
)
# target_link_libraries(main)


#############################################
# Unit tests

# enable CTest testing
enable_testing()

# Add a testing executable
add_executable(sample1_unittest unit_test/sample1_unittest.cc  ${SOURCES})
target_include_directories(sample1_unittest
    PUBLIC
        ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(sample1_unittest
    GTest::GTest
    GTest::Main
)

add_test(test_all sample1_unittest)
