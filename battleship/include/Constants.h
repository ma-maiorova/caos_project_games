#pragma once

#include <string>
#include <vector>

namespace Constants {

const int BOARD_SIZE = 10;
const int MENU_ITEMS_COUNT = 2;

const std::vector<int> SHIP_LENGTHS = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
const std::vector<int> SHIP_COUNTS = {1, 2, 3, 4};

// Коды цветов для консоли
const std::string COLOR_RESET = "\033[0m";
const std::string COLOR_RED = "\033[31m";
const std::string COLOR_GREEN = "\033[32m";
const std::string COLOR_BLUE = "\033[34m";
const std::string COLOR_YELLOW = "\033[33m";
const std::string COLOR_CYAN = "\033[36m";

// Символы для отображения
const char EMPTY_CELL = '~';
const char SHIP_CELL = 'O';
const char HIT_CELL = 'X';
const char MISS_CELL = '*';
const char SELECTOR = '>';
const char CURSOR = '#';

// Состояния игры
enum GameState { MAIN_MENU, SHIP_PLACEMENT, BATTLE, GAME_OVER, EXIT };

} // namespace Constants