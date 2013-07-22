cmake_minimum_required (VERSION 2.8)

option (USE_CLANG "Using clang/clang++" ON)
option (USE_GCC "Using gcc/g++" OFF)
option (DEBUG "Debug Build" ON)

if(USE_CLANG)
    set (CMAKE_CXX_COMPILER clang++)
    set (CMAKE_C_COMPILER clang)
elseif(USE_GCC)
    set (CMAKE_CXX_COMPILER g++)
    set (CMAKE_C_COMPILER gcc)
endif(USE_CLANG)

project(tent-client-cpp)

if(DEBUG)
    set(CMAKE_CXX_FLAGS "-g3 -ggdb -Wall")
else(DEBUG)
    set(CMAKE_CXX_FLAGS "-w")
endif(DEBUG)

add_subdirectory("vendor/cpp-netlib")


