#include "Constants.h"
#include "Game.h"
#include <iostream>

int main() {
    Game game;
    game.Run();
    std::cout << Constants::BATTLE << std::endl;
    std::cout << "Hello world!\n";
    return 0;
}