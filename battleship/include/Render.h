#pragma once

#include "Menu.h"
#include "Player.h"
#include "Constants.h"
#include <string>

class Rendere {
public:
    static void clearScreen();
    static void renderMainMenu(const Menu& menu);
    // static void renderShipPlacement(const Player& player, const std::vector<int>& remainingShips,
    // int cursorX, int cursorY, bool placing); static void renderBattle(const Player&
    // currentPlayer, bool showOwnBoard, int cursorX, int cursorY); static void renderGameOver(const
    // Player& winner); static void renderRules(); static void renderCursor(int x, int y, bool
    // isOwnBoard); static void renderStats(const Player& player1, const Player& player2);
};
