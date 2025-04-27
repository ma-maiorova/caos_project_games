#include "MainLogic.h"
#include <clocale>

#ifdef _WIN32

#include <windows.h>
#include <io.h>
#include <fcntl.h>

#endif

int main() {
#ifdef _WIN32 // для поддержки русского языка
    std::setlocale(LC_ALL, ".65001");

    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    MainLogic play;
    play.Play();
    return 0;
}
