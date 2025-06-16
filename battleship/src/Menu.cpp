#include "Menu.h"

battleship::Menu::Menu(const std::vector<std::string>& items) : items_(items), selected_index_(0) {
}

void battleship::Menu::MoveUp() {
    selected_index_ = (selected_index_ - 1 + items_.size()) % items_.size();
}

void battleship::Menu::MoveDown() {
    selected_index_ = (selected_index_ + 1) % items_.size();
}

int battleship::Menu::GetSelectedIndex() const {
    return selected_index_;
}

const std::vector<std::string>& battleship::Menu::GetItems() const {
    return items_;
}