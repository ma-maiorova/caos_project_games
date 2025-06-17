#include "InputHandler.h"

#ifdef _WIN32

#include <conio.h>
#include <windows.h>

#include <iostream>

void battleship::InputHandler::Init() {
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // setvbuf(stdout, nullptr, _IONBF, 0);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor_info;
    GetConsoleCursorInfo(hConsole, &cursor_info);
    cursor_info.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursor_info);

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

void battleship::InputHandler::Cleanup() {
}

int battleship::InputHandler::GetInput() {
    if (_kbhit()) {
        int ch = _getch();
        if (ch == 224) {
            ch = _getch();
            switch (ch) {
                case 72:
                    return 'U';
                case 80:
                    return 'D';
                case 75:
                    return 'L';
                case 77:
                    return 'R';
                default:
                    return ch;
            }
        }
        return ch;
    }
    return 0;
}

void battleship::InputHandler::WaitForEnter() {
    while (_getch() != '\r') {
    }
}

#else

#include <termios.h>
#include <unistd.h>

static struct termios old_settings, new_settings;

void battleship::InputHandler::Init() {
    tcgetattr(STDIN_FILENO, &old_settings);  // Сохраняем текущие настройки
    new_settings = old_settings;
    new_settings.c_lflag &= ~(ICANON | ECHO);  // Отключаем канонический режим и эхо
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);  // Применяем новые настройки
}

void battleship::InputHandler::Cleanup() {
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);  // Восстанавливаем настройки
}

int battleship::InputHandler::GetInput() {
    char buf[3] = {0};
    int nread = read(STDIN_FILENO, buf, 3);

    if (nread == 1) {
        return buf[0];  // Обычный символ

    } else if (nread == 3 && buf[0] == 27 && buf[1] == '[') {
        // Стрелки
        switch (buf[2]) {
            case 'A':
                return 'U';  // Up
            case 'B':
                return 'D';  // Down
            case 'C':
                return 'R';  // Right
            case 'D':
                return 'L';  // Left
            default:
                return 0;
        }
    }
    return 0;
}

void battleship::InputHandler::WaitForEnter() {
    while (GetInput() != '\n') {
    }
}

#endif