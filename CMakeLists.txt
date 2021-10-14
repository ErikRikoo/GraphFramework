cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME GraphFramework)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

file(
        GLOB_RECURSE
        project_sources
        src/*)

include_directories(inc)
add_executable(${PROJECT_NAME} ${project_sources})

