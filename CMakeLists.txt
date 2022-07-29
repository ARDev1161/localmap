cmake_minimum_required(VERSION 3.5)

project(localmap LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

enable_testing()

set(Settings
    mapsettings.h mapsettings.cpp
)

set(Cell
    cell.h cell.cpp
)

set(Level
    level.h level.cpp
)

set(Map
    localmap.h localmap.cpp
)

set(libLocalMap
    ${Settings}
    ${Cell}
    ${Level}
    ${Map}
)

add_library(localmap
            SHARED
            ${libLocalMap}
           )

add_executable(localmap_test main.cpp
                ${libLocalMap}
)

#target_link_libraries(
#  localmap_test
#  gtest
#  gtest_main
#)

#include(GoogleTest)
#gtest_discover_tests(localmap_test)
