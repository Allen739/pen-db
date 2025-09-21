# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(PenDB VERSION 0.1 LANGUAGES CXX)

# Set c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)  

# Include directories
include_directories(include)

# Add the exacutable
add_executable(pen-db
    src/db.cpp
    src/api.cpp
)

# Optional: compiler warnings (good practicve)

if(MSVC)
    target_compile_options(pen-db PRIVATE /W4 /permissive-)
else()
    target_compile_options(pen-db PRIVATE -Wall -Wextra -pedantic -Werror)
endif()