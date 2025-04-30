#include "InputHandler.h"

#ifdef _WIN32

#include <conio.h>
#include <windows.h>

void InputHandler::init() {
}

void InputHandler::cleanup() {
}

int InputHandler::getInput() {
    if (_kbhit()) {
        return _getch();
    }
    return 0;
}

void InputHandler::waitForEnter() {
    while (_getch() != '\r') {
    }
}

#else

#include <termios.h>
#include <unistd.h>

static struct termios old_settings, new_settings;

void InputHandler::Init() {
    tcgetattr(STDIN_FILENO, &old_settings);  // Сохраняем текущие настройки
    new_settings = old_settings;
    new_settings.c_lflag &= ~(ICANON | ECHO);  // Отключаем канонический режим и эхо
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);  // Применяем новые настройки
}

void InputHandler::Cleanup() {
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);  // Восстанавливаем настройки
}

int InputHandler::GetInput() {
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

void InputHandler::WaitForEnter() {
    while (GetInput() != '\n') {
    }
}

#endif