#include "Game.h"
#include "helpers.h"
#include <iostream>
#include <algorithm>

Game::Game(const std::wstring &secret_word, int lives_level) {
    if (secret_word.empty())
        throw std::invalid_argument("Неверное слово");

    this->secret_word = secret_word;
    user_word.assign(secret_word.size(), L'_');

    if (lives_level == 1)
        cur_user_lives = std::min<int>(secret_word.size() - 1, MAX_USER_LIVES);
    else if (lives_level == 2)
        cur_user_lives = std::min<int>(secret_word.size() - secret_word.size() / 3, MAX_USER_LIVES);
    else if (lives_level == 3)
        cur_user_lives = std::min<int>(secret_word.size() - secret_word.size() / 2, MAX_USER_LIVES);
    else
        cur_user_lives = MAX_USER_LIVES;

    user_lives = cur_user_lives;
}

bool Game::checkLetter(wchar_t letter) {
    letter = std::towlower(letter);
    if (wrong_letters.contains(letter))
        return false;

    bool letter_found = false;
    for (size_t i = 0; i < secret_word.size(); ++i) {
        if (letter == secret_word[i]) {
            user_word[i] = letter;
            letter_found = true;
        }
    }
    if (letter_found) {
        correct_letters.insert(letter);
    } else {
        wrong_letters.insert(letter);
        ++errors;
        --cur_user_lives;
    }
    return letter_found;
}

bool Game::gameOver() const {
    return user_lives == errors || secret_word == user_word;
}

int Game::getUserLives() const { return cur_user_lives; }

void Game::playGame() {
    while (!gameOver()) {
        output.printWord(user_word);
        output.printCorrectLetters(correct_letters);
        output.printErrorLetters(wrong_letters);
        output.printErrors(errors, cur_user_lives);

        std::wcout << L"Введите букву: ";
        std::wstring input;
        std::getline(std::wcin, input);
        trim_ws(input);
        if (input.size() != 1 || !std::iswalpha(input[0])) {
            std::wcout << L"Неверный ввод. Пожалуйста, введите одну букву.\n";
            continue;
        }

        wchar_t cur_letter = std::towlower(input[0]);
        if (!checkLetter(cur_letter))
            std::wcout << L"Неправильная буква, осталось попыток: " << getUserLives() << L'\n';
        else
            std::wcout << L"Правильная буква!\n";

        output.printGallow(errors, user_lives);
    }

    if (secret_word == user_word) {
        std::wcout << L"Вы угадали слово: " << secret_word << L'\n';
    } else {
        std::wcout << L"Вы проиграли( Загаданное слово: " << secret_word << L'\n';
        output.printGallow(errors, user_lives);
    }
}
