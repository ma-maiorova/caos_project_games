#include "Board.h"

#include <algorithm>
#include <iostream>

battleship::Board::Board()
    : grid_(constants::kBoardSize, std::vector<char>(constants::kBoardSize, constants::kEmptyCell)),
      temp_ship_cells_(constants::kBoardSize, std::vector<bool>(constants::kBoardSize, false)) {
}

bool battleship::Board::PlaceShip(const std::vector<std::pair<int, int>>& cells) {
    if (!CanPlaceShip(cells)) {
        return false;
    }

    auto ship = std::make_shared<Ship>(cells.size());
    for (const auto& cell : cells) {
        grid_[cell.first][cell.second] = constants::kShipCell;
        ship->AddCell(cell.first, cell.second);
    }
    ships_.push_back(ship);
    return true;
}

bool battleship::Board::CanPlaceShip(const std::vector<std::pair<int, int>>& cells) const {
    for (const auto& cell : cells) {
        if (cell.first < 0 || cell.first >= constants::kBoardSize || cell.second < 0 ||
            cell.second >= constants::kBoardSize) {
            return false;
        }

        if (!IsCellEmpty(cell.first, cell.second)) {
            return false;
        }

        if (!IsAdjacentCellEmpty(cell.first, cell.second)) {
            return false;
        }
    }
    return true;
}

void battleship::Board::SetTempShipCell(int x, int y) {
    if (x >= 0 && x < constants::kBoardSize && y >= 0 && y < constants::kBoardSize) {
        temp_ship_cells_[x][y] = true;
    }
}

bool battleship::Board::IsTempShipCell(int x, int y) const {
    if (x >= 0 && x < constants::kBoardSize && y >= 0 && y < constants::kBoardSize) {
        return temp_ship_cells_[x][y];
    }
    return false;
}

bool battleship::Board::IsAdjacentCellEmpty(int x, int y) const {
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < constants::kBoardSize && ny >= 0 && ny < constants::kBoardSize &&
                !IsCellEmpty(nx, ny)) {
                return false;
            }
        }
    }
    return true;
}

bool battleship::Board::RemoveShip(int x, int y) {
    for (auto it = ships_.begin(); it != ships_.end(); ++it) {
        if ((*it)->Contains(x, y)) {
            for (const auto& cell : (*it)->GetCells()) {
                grid_[cell.first][cell.second] = constants::kEmptyCell;
            }
            ships_.erase(it);
            return true;
        }
    }
    return false;
}

bool battleship::Board::Attack(int x, int y, std::string& attack_status) {
    if (x < 0 || x >= constants::kBoardSize || y < 0 || y >= constants::kBoardSize) {
        attack_status = "Вы вышли за пределы поля";
        return false;
    }

    if (IsCellHit(x, y) || IsCellMiss(x, y)) {
        attack_status = "Вы уже стреляли сюда, выберите другую клетку";
        return false;
    }

    if (IsCellShip(x, y)) {
        grid_[x][y] = constants::kHitCell;
        for (auto& ship : ships_) {
            if (ship->Contains(x, y)) {
                ship->Hit();
                if (ship->IsSunk()) {
                    attack_status = "Вы потопили корабль противника! Можете продолжать ход";
                    for (const auto& cell : ship->GetCells()) {
                        grid_[cell.first][cell.second] = constants::kSunkShipCell;
                    }
                }
                attack_status = "Подбит! Можете продолжать ход";
                return true;
            }
        }
    } else {
        attack_status = "Промах! Передайте ход другому игроку, нажав клавишу \"Enter\" ";
        grid_[x][y] = constants::kMissCell;
    }

    return false;
}

bool battleship::Board::IsCellEmpty(int x, int y) const {
    return grid_[x][y] == constants::kEmptyCell;
}

bool battleship::Board::IsCellHit(int x, int y) const {
    return grid_[x][y] == constants::kHitCell;
}

bool battleship::Board::IsCellMiss(int x, int y) const {
    return grid_[x][y] == constants::kMissCell;
}

bool battleship::Board::IsCellShip(int x, int y) const {
    return grid_[x][y] == constants::kShipCell;
}

bool battleship::Board::IsCellSunk(int x, int y) const {
    if (x < 0 || x >= constants::kBoardSize || y < 0 || y >= constants::kBoardSize) {
        return false;
    }
    return grid_[x][y] == constants::kSunkShipCell;
}

const std::vector<std::shared_ptr<battleship::Ship>>& battleship::Board::GetShips() const {
    return ships_;
}

bool battleship::Board::AllShipsSunk() const {
    for (const auto& ship : ships_) {
        if (!ship->IsSunk()) {
            return false;
        }
    }
    return true;
}

void battleship::Board::Clear() {
    grid_ = std::vector<std::vector<char>>(
        constants::kBoardSize, std::vector<char>(constants::kBoardSize, constants::kEmptyCell));
    ships_.clear();
}