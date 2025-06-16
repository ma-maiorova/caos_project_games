#pragma once

#include "Constants.h"
#include "Ship.h"

#include <memory>

namespace battleship {

class Board {
public:
    Board();

    bool PlaceShip(const std::vector<std::pair<int, int>>& cells);
    bool CanPlaceShip(const std::vector<std::pair<int, int>>& cells) const;
    bool RemoveShip(int x, int y);

    void SetTempShipCell(int x, int y);
    bool IsTempShipCell(int x, int y) const;

    bool Attack(int x, int y, std::string& attack_status);

    bool IsCellEmpty(int x, int y) const;
    bool IsCellHit(int x, int y) const;
    bool IsCellMiss(int x, int y) const;
    bool IsCellShip(int x, int y) const;
    bool IsCellSunk(int x, int y) const;

    void Hide() {
        hidden_ = true;
    }
    void ShowHide() {
        hidden_ = !hidden_;
    }
    bool IsHidden() const {
        return hidden_;
    }

    const std::vector<std::shared_ptr<Ship>>& GetShips() const;
    bool AllShipsSunk() const;

    void Clear();

private:
    bool hidden_ = false;

    std::vector<std::vector<char>> grid_;
    std::vector<std::shared_ptr<Ship>> ships_;

    std::vector<std::vector<bool>> temp_ship_cells_;

    bool IsAdjacentCellEmpty(int x, int y) const;
};
}  // namespace battleship