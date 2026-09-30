cmake_minimum_required(VERSION 3.15)

project(TheCrons)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
    TheCrons

    src/main.cpp    
    src/core/Board.cpp
    
)