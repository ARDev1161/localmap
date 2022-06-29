cmake_minimum_required(VERSION 3.5)

project(localmap LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)

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

add_library(LocalMap
            SHARED
            ${libLocalMap}
           )

add_executable(localmap main.cpp
                ${libLocalMap}
)
