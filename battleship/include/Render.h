#pragma once

#include "Menu.h"
#include "Player.h"

#include <iostream>

namespace battleship {

class Render {
public:
    static void ClearScreen();
    static void RenderMainMenu(const battleship::Menu& menu);
    static void RenderRules();
    static void RenderShipPlacement(battleship::Player& player,
                                    const std::vector<int>& remaining_ships, int cursor_x,
                                    int cursor_y, bool is_placing,
                                    const battleship::Board& temp_board);
    static void RenderBattle(battleship::Player& current_player, int cursor_x, int cursor_y,
                             const std::string& attack_status);
    static void RenderSwitching(const battleship::Player& next_player);
    static void RenderGameOver(battleship::Player& winner, const std::string& looser_name);

    static void PrintColoredString(const std::string& color, const std::string& string) {
        std::cout << color << string << constants::kColorReset << "\n\n";
    }

    static void PrintBoard(const battleship::Board& board, bool own = true,
                           bool show_cursor = false, int cursor_x = 0, int cursor_y = 0,
                           const battleship::Board& temp_board = {});

private:
    static void PrintHeaderBoardLine() {
        std::cout << "  ";
        for (int i = 0; i < constants::kBoardSize; ++i) {
            std::cout << static_cast<char>('A' + i) << " ";
        }
        std::cout << '\n';
    }

    static void PrintColoredItem(const std::string& color, char item) {
        std::cout << color << item << constants::kColorReset;
    }

    static void PrintEmptyCell() {
        PrintColoredItem(constants::kColorBlue, constants::kEmptyCell);
    }

    static void PrintCursor() {
        PrintColoredItem(constants::kColorGreen, constants::kCursor);
    }

    static void PrintTempShipCell() {
        PrintColoredItem(constants::kColorYellow, constants::kShipCell);
    }

    static void PrintShipCell() {
        std::cout << constants::kShipCell;
    }

    static void PrintMissCell() {
        std::cout << constants::kMissCell;
    }

    static void PrintHitCell() {
        PrintColoredItem(constants::kColorRed, constants::kHitCell);
    }

    static void PrintSunkShipCell() {
        PrintColoredItem(constants::kColorMagenta, constants::kSunkShipCell);
    }
};
}  // namespace battleship