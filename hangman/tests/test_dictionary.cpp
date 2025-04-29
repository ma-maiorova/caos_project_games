#include <gtest/gtest.h>
#include "../categories/Dictionary.h"
#include "../categories/CategoryAnimal.h"

TEST(DictionaryTest, RandomCategoryRange) {
    Dictionary dict;
    for (int i = 0; i < 20; ++i) {
        std::wstring c = dict.getRandomCategory();
        EXPECT_TRUE(c == L"1" || c == L"2" || c == L"3" || c == L"4");
    }
}

TEST(DictionaryTest, RandomLevelValues) {
    Dictionary dict;
    for (int i = 0; i < 20; ++i) {
        std::wstring lvl = dict.getRandomLevel();
        EXPECT_TRUE(lvl == L"easy" || lvl == L"medium" || lvl == L"hard");
    }
}

TEST(DictionaryTest, RandomWordInAnimalEasy) {
    Dictionary dict;
    auto const &allowed = CategoryAnimal::getLevel(L"easy");
    for (int i = 0; i < 20; ++i) {
        std::wstring w = dict.getRandomWord(L"Animal", L"easy");
        EXPECT_NE(std::find(allowed.begin(), allowed.end(), w), allowed.end());
    }
}
