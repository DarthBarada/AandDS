cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(fibbonachi_logn)

if(BUILD_TESTS)

find_package(GTest CONFIG REQUIRED)

set(SOURCES ${PROJECT_NAME}_sources)

add_library(${SOURCES} STATIC fibbonchi_logn.cpp)

add_executable(tests_fibbonachi test.cpp)

target_include_directories(
        tests_fibbonachi
        PUBLIC
        ${GTEST_ROOT}/include
)
target_link_libraries(
    tests_fibbonachi
    GTest::gtest
    GTest::gtest_main
    ${SOURCES}
)

endif()