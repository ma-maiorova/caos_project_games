#include <gtest/gtest.h>
#include "../Game.h"

TEST(GameTest, RepeatedWrongLetterNoExtraPenalty) {
    Game g(L"abc", 1);
    int lives1 = g.getUserLives();
    EXPECT_FALSE(g.checkLetter(L'x'));
    EXPECT_EQ(g.getUserLives(), lives1 - 1);
    EXPECT_FALSE(g.checkLetter(L'x'));
    EXPECT_EQ(g.getUserLives(), lives1 - 1);
}

TEST(GameTest, RepeatedCorrectLetterNoPenalty) {
    Game g(L"aba", 1);
    int lives1 = g.getUserLives();
    EXPECT_TRUE(g.checkLetter(L'a'));
    EXPECT_EQ(g.getUserLives(), lives1);
    EXPECT_TRUE(g.checkLetter(L'a'));
    EXPECT_EQ(g.getUserLives(), lives1);
}

TEST(GameTest, GameOverAfterAllCorrectLetters) {
    Game g(L"zz", 1);
    EXPECT_FALSE(g.gameOver());
    EXPECT_TRUE(g.checkLetter(L'z'));
    EXPECT_TRUE(g.gameOver());
}


TEST(GameTest, MixedCaseAndUpperCase) {
    Game g(L"TeSt", 1);
    EXPECT_TRUE(g.checkLetter(L't'));
    EXPECT_TRUE(g.checkLetter(L'T'));
    EXPECT_EQ(g.getUserLives(), g.getUserLives());
}
