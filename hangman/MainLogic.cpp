#include "MainLogic.h"
#include "helpers.h"
#include <iostream>

void MainLogic::Play() {
    std::map<std::wstring, std::wstring> how_level{
            {L"1", L"easy"},
            {L"2", L"medium"},
            {L"3", L"hard"}
    };
    std::map<std::wstring, std::wstring> how_category{
            {L"1", L"Animal"},
            {L"2", L"Cities"},
            {L"3", L"Food"},
            {L"4", L"Sport"}
    };

    Dictionary Dictionary;
    std::wcin.imbue(std::locale(""));

    for (;;) {
        std::wcout << L"Игра Виселица, привет!\nХотите поиграть? (да/нет)\n";
        std::wstring input;
        std::getline(std::wcin, input);
        trim_ws(input);
        if (input == L"нет") {
            std::wcout << L"Пока!\n";
            break;
        }
        if (input != L"да") {
            std::wcout << L"Некорректный ввод, попробуйте снова.\n";
            continue;
        }

        std::wcout << L"Выберите категорию слов: 1-Животные, 2-Города, 3-Еда, 4-Спорт (Enter — случайно): \n";
        std::wstring category;
        std::getline(std::wcin, category);
        trim_ws(category);
        std::wcout << category << "\n";
        if (category.empty() || !how_category.count(category)) {
            category = Dictionary.getRandomCategory();
        }
        category = how_category[category];
        std::wcout << L"Ваша категория: " << category << L'\n';

        std::wcout << L"Выберите уровень сложности набора слов 1-3 (Enter — случайно): \n";
        std::wstring level;
        std::getline(std::wcin, level);
        trim_ws(level);
        if (level.empty() || !how_level.count(level)) {
            level = Dictionary.getRandomLevel();
        }
        level = how_level[level];
        std::wcout << L"Ваш уровень сложности: " << level << L'\n';

        std::wcout << L"Выберите уровень сложности количества жизней 1-3 (Enter — случайно): \n";
        std::wstring level_str;
        std::getline(std::wcin, level_str);
        trim_ws(level_str);
        int level_lives = 0;
        if (level_str.empty() || (level_str != L"1" && level_str != L"2" && level_str != L"3")) {
            level_lives = std::stoi(Dictionary.getRandomCategory()); // 1-3
        }
        level_lives = std::stoi(level_str);
        std::wcout << L"Ваш уровень жизней: " << level_lives << L'\n';

        std::wstring secret_word = Dictionary.getRandomWord(category, level);

        Game game(secret_word, level_lives);
        std::wcout << L"У вас есть " << game.getUserLives() << L" попыток.\n";
        game.playGame();

        std::wcout << L"Игра завершена! Нажмите Enter, чтобы продолжить.\n";
        std::getline(std::wcin, input);
        trim_ws(input);
    }
}
