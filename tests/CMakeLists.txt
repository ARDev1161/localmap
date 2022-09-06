cmake_minimum_required(VERSION 3.5)

project(localmap-tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)

#include(FetchContent)
#FetchContent_Declare(
#  googletest
#  GIT_REPOSITORY https://github.com/google/googletest.git
#  GIT_TAG release-1.12.1
#)

enable_testing()

add_executable(${PROJECT_NAME} celltests.cpp
)

target_link_libraries(${PROJECT_NAME}
    liblocalmap
    gtest
    gmock
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
