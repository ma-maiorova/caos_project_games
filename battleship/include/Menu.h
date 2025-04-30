#pragma once

#include <string>
#include <vector>

class Menu {
public:
    Menu(const std::vector<std::string> &items);

    void MoveUp();
    void MoveDown();
    int GetSelectedIndex() const;
    const std::vector<std::string> &GetItems() const;

private:
    std::vector<std::string> items_;
    int selected_index_;
};
