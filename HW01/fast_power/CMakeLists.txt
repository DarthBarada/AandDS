cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_MAIN "Build main" OFF)
option(BUILD_COVERAGE "Build coverage" OFF)
option(BUILD_TESTS "Build coverage" OFF)

project(fast_power)

if(BUILD_TESTS)

find_package(GTest CONFIG REQUIRED)

set(SOURCES ${PROJECT_NAME}_sources)

add_library(${SOURCES} STATIC fast_power.cpp)

add_executable(tests_power test.cpp)

target_include_directories(
        tests_power
        PUBLIC
        ${GTEST_ROOT}/include
)
target_link_libraries(
    tests_power
    GTest::gtest
    GTest::gtest_main
    ${SOURCES}
)
enable_testing()
add_test(NAME unit_tests COMMAND tests_power)

endif()