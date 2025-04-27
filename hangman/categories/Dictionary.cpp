#include "Dictionary.h"

static std::mt19937 rnd{std::random_device{}()};

std::wstring Dictionary::getRandomCategory() const {
    std::uniform_int_distribution<int> dist(1, 4);
    return std::to_wstring(dist(rnd));
}

std::wstring Dictionary::getRandomLevel() const {
    std::uniform_int_distribution<int> dist(1, 3);
    int lvl = dist(rnd);
    return (lvl == 1 ? L"easy" : lvl == 2 ? L"medium" : L"hard");
}

std::wstring Dictionary::getRandomWord(const std::wstring &cat,
                                       const std::wstring &type) const {
    const std::vector<std::wstring> *words = nullptr;
    if (cat == L"Animal") words = &CategoryAnimal::getLevel(type);
    else if (cat == L"Cities") words = &CategoryCities::getLevel(type);
    else if (cat == L"Food") words = &CategoryFood::getLevel(type);
    else words = &CategorySport::getLevel(type);

    std::uniform_int_distribution<int> dist(0, static_cast<int>(words->size() - 1));
    return (*words)[dist(rnd)];
}
