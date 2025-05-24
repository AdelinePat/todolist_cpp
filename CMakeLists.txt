cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(TODO VERSION 0.1.0 LANGUAGES C CXX)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG_MODE)   
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(-DRELEASE_MODE)
endif()

add_executable(TODO
    src/choice_redirection.cpp
    src/CRUD.cpp
    src/csv_manager.cpp
    src/display.cpp
    src/main.cpp
    src/sanitize_input.cpp
    src/utils.cpp
    )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)