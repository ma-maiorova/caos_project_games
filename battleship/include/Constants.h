#pragma once

#include <string>
#include <vector>

namespace constants {

const int kBoardSize = 10;
const int kMenuItemsCount = 2;

const std::vector<int> kShipLengths = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
const std::vector<int> kShipCounts = {4, 3, 2, 1};

// Для быстрой отладки
// const std::vector<int> kShipCounts = {0, 1, 0, 0};

// Коды цветов для консоли
const std::string kColorReset = "\033[0m";
const std::string kColorRed = "\033[31m";
const std::string kColorGreen = "\033[32m";
const std::string kColorYellow = "\033[33m";
const std::string kColorBlue = "\033[34m";
const std::string kColorMagenta = "\033[35m";
const std::string kColorCyan = "\033[36m";

// Символы для отображения
const char kEmptyCell = '~';
const char kShipCell = 'O';
const char kHitCell = 'x';
const char kSunkShipCell = 'X';
const char kMissCell = '*';
const char kSelector = '>';
const char kCursor = '#';

// Номера клавиш
const int kArrowUp = 85;
const int kArrowDown = 68;
const int kArrowRight = 82;
const int kArrowLeft = 76;

const int kEscape = 27;
const int kSpace = 32;

#ifdef _WIN32
const int kDelete = 8;
const int kEnter = 13;
#else
const int kDelete = 127;
const int kEnter = 10;
#endif

// Состояния игры
enum GameState { MAIN_MENU, SHIP_PLACEMENT, BATTLE, SWITCHING, GAME_OVER, EXIT };

} // namespace Constants