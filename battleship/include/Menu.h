#pragma once

#include <string>
#include <vector>

class Menu {
public:
    Menu(const std::vector<std::string> &items);

    void moveUp();
    void moveDown();
    int getSelectedIndex() const;
    const std::vector<std::string> &getItems() const;

private:
    std::vector<std::string> items;
    int selectedIndex;
};
