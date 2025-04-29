cmake_minimum_required(VERSION 3.29)
project(hangman_game LANGUAGES CXX)

set(GAME_SOURCES_HANGMAN
        Game.cpp
        Output.cpp
        MainLogic.cpp
        categories/Dictionary.cpp
        categories/CategoryAnimal.cpp
        categories/CategoryCities.cpp
        categories/CategoryFood.cpp
        categories/CategorySport.cpp
)
add_library(game_lib_hangman STATIC ${GAME_SOURCES_HANGMAN})
target_include_directories(game_lib_hangman PUBLIC
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/categories
)

add_executable(hangman_game
        main.cpp
)

target_link_libraries(hangman_game PRIVATE game_lib_hangman)

set(TEST_SOURCES_HANGMAN
        tests/test_category.cpp
        tests/test_dictionary.cpp
        tests/test_game.cpp
        tests/test_game_extra.cpp
        tests/test_output.cpp
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
