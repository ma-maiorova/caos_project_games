#include "Output.h"

const std::vector<std::wstring> Output::Gallow = {
        L"  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
        L"  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
        L"  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
        L"  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
        L"  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
        L"  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
        L"  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========="
};

void Output::printWord(const std::wstring &word) const {
    std::wcout << L"Сейчас слово выглядит так: " << word << L'\n';
}

void Output::printErrors(int errors, int lives) const {
    std::wcout << L"Уже было " << errors << L" попыток, осталось " << lives << L'\n';
}

void Output::printCorrectLetters(const std::set<wchar_t> &cur) const {
    std::wcout << L"Угаданные буквы: ";
    for (auto c: cur) std::wcout << c << L' ';
    std::wcout << L'\n';
}

void Output::printErrorLetters(const std::set<wchar_t> &cur) const {
    std::wcout << L"Неправильные буквы: ";
    for (auto c: cur) std::wcout << c << L' ';
    std::wcout << L'\n';
}

void Output::printGallow(int step, int lives) const {
    if (lives <= 6 && step == lives)
        std::wcout << Gallow.back() << L'\n';
    else
        std::wcout << Gallow[std::min(step, 6)] << L'\n';
}
