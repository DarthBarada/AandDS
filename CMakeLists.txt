cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_MAIN "Build main" OFF)
option(BUILD_COVERAGE "Build coverage" OFF)
option(BUILD_TESTS "Build tests" OFF)

option(BUILD_HW1 "Build home work 1" ON)

include("tools/gate/cmake/HunterGate.cmake")

HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.251.tar.gz"
    SHA1 "5659b15dc0884d4b03dbd95710e6a1fa0fc3258d"
)

project(AandDS)

string(APPEND CMAKE_CXX_FLAGS " -pedantic -Werror -Wall -Wextra")
string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-command-line-argument")
string(APPEND CMAKE_CXX_FLAGS " -Wshadow -Wnon-virtual-dtor")

if (BUILD_TESTS)
    hunter_add_package(GTest)
    find_package(GTest CONFIG REQUIRED)
endif()

if (BUILD_HW1)
    add_subdirectory(HW01 ${CMAKE_CURRENT_SOURCE_DIR}/HW01)
endif()