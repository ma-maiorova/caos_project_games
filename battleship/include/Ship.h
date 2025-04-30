#include "Constants.h"

class Ship {
public:
    Ship(int size);

    int GetSize() const;
    bool IsSunk() const;
    void Hit();
    bool Contains(int x, int y) const;
    void AddCell(int x, int y);
    const std::vector<std::pair<int, int>>& GetCells() const;

private:
    int size_;
    std::vector<std::pair<int, int>> cells_;
    std::vector<int> hits_;
};