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

#add_subdirectory("vendor/cpp-netlib-0.10.1")

include(ExternalProject)
ExternalProject_Add(cppnetlib
    #    URL ""
    SOURCE_DIR "../vendor/cpp-netlib-0.10.1"
    BUILD_IN_SOURCE 1
    CONFIGURE_COMMAND
    BUILD_COMMAND make -j4
    INSTALL_COMMAND ""
    )

ExternalProject_Get_Property(cppnetlib INSTALL_DIR)
set(CPPNL_DIR ${INSTALL_DIR})
message(STATUS " CPPNL INSTALL DIR ")
message(STATUS ${CPPNL_DIR})


