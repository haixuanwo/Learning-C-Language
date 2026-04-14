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

file(GLOB_RECURSE TEST_SOURCES unit_test/*.cpp unit_test/*.cc)

# Add a testing executable
add_executable(unit_test ${TEST_SOURCES} ${SOURCES})
target_include_directories(unit_test
    PUBLIC
        ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(unit_test
    GTest::GTest
    GTest::Main
)

add_test(test_all unit_test)
