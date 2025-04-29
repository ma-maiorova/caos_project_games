cmake_minimum_required(VERSION 3.10)
project(caos_project_games VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest-1.16.0)

add_subdirectory(hangman)
add_subdirectory(battleship)