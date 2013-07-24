cmake_minimum_required (VERSION 2.8)

option (USE_CLANG "Using clang/clang++" ON)
option (USE_GCC "Using gcc/g++" OFF)
option (DEBUG "Debug Build" ON)
option (TESTS "Test Suite" ON)

if(USE_CLANG)
    set (CMAKE_CXX_COMPILER clang++)
    set (CMAKE_C_COMPILER clang)
elseif(USE_GCC)
    set (CMAKE_CXX_COMPILER g++)
    set (CMAKE_C_COMPILER gcc)
endif(USE_CLANG)

project(tent-client-cpp)
set(Boost_COMPONENTS 
    system 
    regex 
    date_time 
    thread 
    filesystem 
    program_options 
    chrono)

find_package( Boost 1.51.0 REQUIRED ${Boost_COMPONENTS})

message(STATUS "SOURCE DIR : ")
message(STATUS ${tent-client-cpp_SOURCE_DIR})

if(DEBUG)
    set(CMAKE_CXX_FLAGS "-g3 -ggdb -Wall")
else(DEBUG)
    set(CMAKE_CXX_FLAGS "-w")
endif(DEBUG)

if(TESTS)
    add_subdirectory(tests)
endif(TESTS)

# Source
include_directories(src)

file(GLOB_RECURSE tent_client_source
     "src/*.cpp"
     "src/*.c"
     )

# Vendor
include_directories(vendor/cpp-netlib-0.10.1)
include_directories(vendor/rapidjson/include)
include_directories(${Boost_INCLUDE_DIRS})

include(ExternalProject)
ExternalProject_Add(cppnetlib
    #    URL ""
    SOURCE_DIR "${tent-client-cpp_SOURCE_DIR}/vendor/cpp-netlib-0.10.1"
    BUILD_IN_SOURCE 0
    CONFIGURE_COMMAND
    BUILD_COMMAND make -j4
    INSTALL_COMMAND ""
    )

#ExternalProject_Get_Property(cppnetlib INSTALL_DIR)
#set(CPPNL_DIR ${INSTALL_DIR})

add_library(tentcpp
    ${tent_client_source})
target_link_libraries(tentcpp
    ${Boost_LIBRARIES})

