#include "Ship.h"

battleship::Ship::Ship(int size) : size_(size), hits_(size, false) {
}

int battleship::Ship::GetSize() const {
    return size_;
}

bool battleship::Ship::IsSunk() const {
    for (bool hit : hits_) {
        if (!hit) {
            return false;
        }
    }
    return true;
}

void battleship::Ship::Hit() {
    for (int& hit : hits_) {
        if (!hit) {
            hit = true;
            break;
        }
    }
}

bool battleship::Ship::Contains(int x, int y) const {
    for (const auto& cell : cells_) {
        if (cell.first == x && cell.second == y) {
            return true;
        }
    }
    return false;
}

void battleship::Ship::AddCell(int x, int y) {
    cells_.emplace_back(x, y);
}

const std::vector<std::pair<int, int>>& battleship::Ship::GetCells() const {
    return cells_;
}