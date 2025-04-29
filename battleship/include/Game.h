#pragma once

#include <iostream>
#include "Player.h"
#include "Menu.h"
#include "Constants.h"

class Game {
public:
    Game() {
        std::cout << "I'm in Game()\n";
    };
    void Run();

private:
    // Player player1;
    // Player player2;
    // Player* currentPlayer;
    // Player* otherPlayer;
    // Constants::GameState state_;
    // Menu main_menu_;

    void ProcessMainMenu();
    void ProcessShipPlacement();
    void ProcessBattle();
    void SwitchPlayer();
    void ResetGame();
};