cmake_minimum_required (VERSION 2.8)

# include lib files
include_directories(${tent-client-cpp_SOURCE_DIR}/src)
file(GLOB_RECURSE tent-client-source
    ${tent-client-cpp_SOURCE_DIR}/src/*.cpp)


include_directories(../vendor/gtest-1.6.0/include)
include_directories(../vendor/rapidjson/include)
# add google test
include(ExternalProject)
ExternalProject_Add(googletest
    URL ""
    SOURCE_DIR "../../vendor/gtest-1.6.0"
    BUILD_IN_SOURCE 0
    CONFIGURE_COMMAND
    BUILD_COMMAND make -j4
    INSTALL_COMMAND ""
    )

ExternalProject_Get_Property(googletest INSTALL_DIR)
set(GT_DIR ${INSTALL_DIR})

message(STATUS "GOOGLE TEST INSTALL DIR : ")
message(STATUS ${GT_DIR})

add_library(google_test_lib STATIC IMPORTED)
set_property(TARGET google_test_lib PROPERTY IMPORTED_LOCATION ${GT_DIR}/src/googletest-build/libgtest.a)

add_executable(tests 
               client_tests.cpp
               )
target_link_libraries (tests 
                       google_test_lib
                       ${Boost_LIBRARIES})

