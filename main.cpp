#include "battleship/include/Game.h"
#include "hangman/MainLogic.h"

#include <clocale>

#ifdef _WIN32

#include <windows.h>
#include <io.h>
#include <fcntl.h>

#endif

int MainMenuRender() {
    char choice;
    std::cout << "Выберите игру:\n1. Виселица\n2. Морской бой\n\n\n\nДля выбора напечатайте "
                     "одну из цифр (1 или 2)\nДля выхода нажмите q"
                  << std::endl;
    while (std::cin >> choice) {
        if (choice == '1' or choice == '2') {
            return choice;
        }
        if (choice == 'q') {
            return -1;
        }
        std::cout << "Выберите игру:\n1. Виселица\n2. Морской бой\n\n\n\nДля выбора напечатайте "
                     "одну из цифр (1 или 2)\nДля выхода нажмите q"
                  << std::endl;
    }
    return 0;
}

void Battleship() {
    battleship::Game game;
    game.Run();
}

void Hangman() {
#ifdef _WIN32  // для поддержки русского языка
    std::setlocale(LC_ALL, ".65001");

    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    try {

        std::setlocale(LC_ALL, "");
        auto loc = std::locale("");
        std::locale::global(loc);
        std::wcout.imbue(loc);
        std::wcin.imbue(loc);
    } catch (const std::exception &e) {
        std::cerr << "Warning: cannot set locale: " << e.what() << "\n";
    }

    MainLogic play;
    play.Play();
}

int main() {
    while (true) {
        std::cout << "main\n";
        switch (MainMenuRender()) {
            case '1':
                Hangman();
                break;
            case '2':
                Battleship();
                break;
            default:
                return 0;
        }
    }
}
