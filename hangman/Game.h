#pragma once

#include "Output.h"
#include <string>
#include <unordered_set>
#include <cwctype>

class Game {
private:
    std::wstring secret_word;
    std::wstring user_word;
    std::set<wchar_t> used_letters;
    std::set<wchar_t> correct_letters;
    std::set<wchar_t> wrong_letters;
    int cur_user_lives = 0;
    int user_lives = 0;
    const int MAX_USER_LIVES = 6;
    int errors = 0;
    Output output;

public:
    explicit Game(const std::wstring &secret_word, int lives_level = 0);

    bool checkLetter(wchar_t letter);

    bool gameOver() const;

    int getUserLives() const;

    void playGame();
};
