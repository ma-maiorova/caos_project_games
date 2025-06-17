#pragma once

#include "Constants.h"

namespace battleship {

class InputHandler {
public:
    static void Init();
    static void Cleanup();
    static int GetInput();
    static void WaitForEnter();
};
}  // namespace battleship