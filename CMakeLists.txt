
cmake_minimum_required(VERSION 3.10)
project(caos_project_games VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest-1.16.0)

include_directories(battleship/include)
include_directories(battleship/src)
include_directories(hangman)

add_executable(game 
                main.cpp
                battleship/src/Game.cpp
                battleship/src/Render.cpp
                battleship/src/Menu.cpp
                battleship/src/InputHandler.cpp
                battleship/src/Player.cpp
                battleship/src/Board.cpp
                battleship/src/Ship.cpp
                hangman/Game.cpp
                hangman/Output.cpp
                hangman/MainLogic.cpp
                hangman/categories/Dictionary.cpp
                hangman/categories/CategoryAnimal.cpp
                hangman/categories/CategoryCities.cpp
                hangman/categories/CategoryFood.cpp
                hangman/categories/CategorySport.cpp)
