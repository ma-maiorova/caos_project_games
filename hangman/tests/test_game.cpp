#include <gtest/gtest.h>
#include "../Game.h"

TEST(GameTest, ConstructorEmptyWordThrows) {
    EXPECT_THROW(Game(L"", 1), std::invalid_argument);
}

TEST(GameTest, InvalidLivesLevelGivesMaxLives) {
    Game g(L"test", 0);
    EXPECT_GE(g.getUserLives(), static_cast<int>(std::wstring(L"test").size()));
}

TEST(GameTest, CheckLetterCorrectAndWrong) {
    Game g(L"aba", 1);
    int before = g.getUserLives();
    EXPECT_TRUE(g.checkLetter(L'a'));
    EXPECT_EQ(g.getUserLives(), before);

    EXPECT_FALSE(g.checkLetter(L'x'));
    EXPECT_EQ(g.getUserLives(), before - 1);
}

TEST(GameTest, GameOverOnErrors) {
    Game g(L"xy", 1);
    EXPECT_FALSE(g.gameOver());
    g.checkLetter(L'z');
    EXPECT_TRUE(g.gameOver());
}

TEST(GameTest, GameOverOnSuccess) {
    Game g(L"hi", 1);
    EXPECT_FALSE(g.gameOver());
    g.checkLetter(L'h');
    g.checkLetter(L'i');
    EXPECT_TRUE(g.gameOver());
}
