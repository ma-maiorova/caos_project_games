#pragma once

#include "Board.h"

class Player {
public:
    Player(const std::string& name);

    const std::string& GetName() const;
    Board& GetOwnBoard();
    Board& GetEnemyBoard();
    void Reset();

    void SetMyBoard(std::shared_ptr<Board> my_board) {
        own_board_ = my_board;
    }

    void SetEnemyBoard(std::shared_ptr<Board> board) {
        enemy_board_ = board;
    }

private:
    std::string name_;
    std::shared_ptr<Board> own_board_ = nullptr;
    std::shared_ptr<Board> enemy_board_ = nullptr;
};