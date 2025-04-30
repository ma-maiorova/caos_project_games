#pragma once

#include <string>
#include <random>

#include "CategorySport.h"
#include "CategoryAnimal.h"
#include "CategoryCities.h"
#include "CategoryFood.h"

class Dictionary {
public:
    std::wstring getRandomCategory() const; // "1"-"4"
    std::wstring getRandomLevel() const; // "easy"/"medium"/"hard"
    std::wstring getRandomWord(const std::wstring &cat,
                               const std::wstring &type) const;
};
