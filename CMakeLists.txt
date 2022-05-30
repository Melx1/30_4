cmake_minimum_required(VERSION 3.21)
project(30_4)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_CPR_TEST OFF)
set(CMAKE_USF_OPENSSI ON)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 6ea2dec23c3df14ac3b27b7d2d6bbff0cb7ba1b0) # The commit hash for 1.8.1. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

add_executable(30.4.1 30.4.1.cpp)
target_link_libraries(30.4.1 PRIVATE cpr::cpr)
add_executable(30.4.2 30.4.2.cpp 30.4.2.cpp)
target_link_libraries(30.4.2 PRIVATE cpr::cpr)
add_executable(30.4.3 30.4.3.cpp 30.4.3.cpp)
target_link_libraries(30.4.3 PRIVATE cpr::cpr)