#include "Menu.h"

Menu::Menu(const std::vector<std::string>& items) : items_(items), selected_index_(0) {}

void Menu::MoveUp() {
    selected_index_ = (selected_index_ - 1 + items_.size()) % items_.size();
}

void Menu::MoveDown() {
    selected_index_ = (selected_index_ + 1) % items_.size();
}

int Menu::GetSelectedIndex() const {
    return selected_index_;
}

const std::vector<std::string>& Menu::GetItems() const {
    return items_;
}