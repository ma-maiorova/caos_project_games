#pragma once

#include "Menu.h"
#include "Player.h"

class Game {
public:
    Game();
    void Run();

private:
    Player player1_;
    Player player2_;
    
    Player* current_player_;
    Player* other_player_;

    constants::GameState state_;
    Menu main_menu_;

    void ProcessMainMenu();
    void ProcessShipPlacement();
    void ProcessBattle();
    void ProcessSwitching();
    void SwitchPlayer();
    void ResetGame();
};