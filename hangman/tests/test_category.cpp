#include <gtest/gtest.h>
#include "../categories/CategoryFood.h"
#include "../categories/CategorySport.h"
#include "../categories/CategoryCities.h"
#include "../categories/CategoryAnimal.h"

TEST(CategoryAnimalTest, EasyLevel) {
    auto const &v = CategoryAnimal::getLevel(L"easy");
    EXPECT_EQ(v.size(), 10);
    EXPECT_EQ(v.front(), L"кот");
    EXPECT_EQ(v.back(), L"лев");
}

TEST(CategoryCitiesTest, InvalidLevelFallsBackToHard) {
    auto const &v = CategoryCities::getLevel(L"unknown");
    EXPECT_EQ(v.size(), 10);
}

TEST(CategoryFoodTest, MediumLevelContainsMango) {
    auto const &v = CategoryFood::getLevel(L"medium");
    EXPECT_NE(std::find(v.begin(), v.end(), L"манго"), v.end());
}

TEST(CategorySportTest, HardLevelContainsCurling) {
    auto const &v = CategorySport::getLevel(L"hard");
    EXPECT_NE(std::find(v.begin(), v.end(), L"кёрлинг"), v.end());
}
