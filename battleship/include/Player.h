#pragma once

#include "Board.h"

namespace battleship {

class Player {
public:
    Player(const std::string& name);

    const std::string& GetName() const;
    battleship::Board& GetOwnBoard();
    battleship::Board& GetEnemyBoard();
    void Reset();

    void SetMyBoard(std::shared_ptr<battleship::Board> my_board) {
        own_board_ = my_board;
    }

    void SetEnemyBoard(std::shared_ptr<battleship::Board> board) {
        enemy_board_ = board;
    }

private:
    std::string name_;
    std::shared_ptr<battleship::Board> own_board_ = nullptr;
    std::shared_ptr<battleship::Board> enemy_board_ = nullptr;
};
}  // namespace battleship