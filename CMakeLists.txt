cmake_minimum_required(VERSION 3.5)

project(localmap LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)

add_subdirectory(src)

add_subdirectory(examples)
add_subdirectory(tests)
