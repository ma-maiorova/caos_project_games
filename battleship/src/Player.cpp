#include "Player.h"

Player::Player(const std::string& name) : name_(name){};

const std::string& Player::GetName() const {
    return name_;
}

Board& Player::GetOwnBoard() {
    return *own_board_;
}

Board& Player::GetEnemyBoard() {
    return *enemy_board_;
}

void Player::Reset() {
    own_board_->Clear();
    enemy_board_->Clear();
}