#include "Ship.h"

Ship::Ship(int size) : size_(size), hits_(size, false) {
}

int Ship::GetSize() const {
    return size_;
}

bool Ship::IsSunk() const {
    for (bool hit : hits_) {
        if (!hit) {
            return false;
        }
    }
    return true;
}

void Ship::Hit() {
    for (int& hit : hits_) {
        if (!hit) {
            hit = true;
            break;
        }
    }
}

bool Ship::Contains(int x, int y) const {
    for (const auto& cell : cells_) {
        if (cell.first == x && cell.second == y) {
            return true;
        }
    }
    return false;
}

void Ship::AddCell(int x, int y) {
    cells_.emplace_back(x, y);
}

const std::vector<std::pair<int, int>>& Ship::GetCells() const {
    return cells_;
}