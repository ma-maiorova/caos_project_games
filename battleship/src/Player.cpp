#include "Player.h"

battleship::Player::Player(const std::string& name) : name_(name){};

const std::string& battleship::Player::GetName() const {
    return name_;
}

battleship::Board& battleship::Player::GetOwnBoard() {
    return *own_board_;
}

battleship::Board& battleship::Player::GetEnemyBoard() {
    return *enemy_board_;
}

void battleship::Player::Reset() {
    own_board_->Clear();
    enemy_board_->Clear();
}