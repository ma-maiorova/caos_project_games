#pragma once

#include <string>
#include <vector>

struct CategoryAnimal {
    static const std::vector<std::wstring> easy;
    static const std::vector<std::wstring> medium;
    static const std::vector<std::wstring> hard;

    static const std::vector<std::wstring> &getLevel(const std::wstring &level);
};