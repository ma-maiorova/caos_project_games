cmake_minimum_required(VERSION 3.29)
project(caos_project_games_hangman LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GAME_SOURCES_HANGMAN
        hangman/Game.cpp
        hangman/Output.cpp
        hangman/MainLogic.cpp
        hangman/categories/Dictionary.cpp
        hangman/categories/CategoryAnimal.cpp
        hangman/categories/CategoryCities.cpp
        hangman/categories/CategoryFood.cpp
        hangman/categories/CategorySport.cpp
)
add_library(game_lib_hangman STATIC ${GAME_SOURCES_HANGMAN})
target_include_directories(game_lib_hangman PUBLIC
        ${CMAKE_SOURCE_DIR}/hangman
        ${CMAKE_SOURCE_DIR}/hangman/categories
)

add_executable(hangman_game
        hangman/main.cpp
)

target_link_libraries(hangman_game PRIVATE game_lib_hangman)

add_subdirectory(${CMAKE_SOURCE_DIR}/googletest-1.16.0)

set(TEST_SOURCES_HANGMAN
        hangman/tests/test_category.cpp
        hangman/tests/test_dictionary.cpp
        hangman/tests/test_game.cpp
        hangman/tests/test_game_extra.cpp
        hangman/tests/test_output.cpp
)

add_executable(hangman_game_tests ${TEST_SOURCES_HANGMAN})
target_link_libraries(hangman_game_tests
        PRIVATE
        game_lib_hangman
        gtest
        gtest_main
)

enable_testing()
include(GoogleTest)
gtest_discover_tests(hangman_game_tests)
