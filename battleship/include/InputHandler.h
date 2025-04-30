#pragma once

#include "Constants.h"

class InputHandler {
public:
    static void Init();
    static void Cleanup();
    static int GetInput();
    static void WaitForEnter();
};