cmake_minimum_required(VERSION 3.10.0)
project(caos_project_games VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(src)

add_executable(battleship_main 
                src/main.cpp
                src/Game.cpp)