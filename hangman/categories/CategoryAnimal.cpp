#include "CategoryAnimal.h"

const std::vector<std::wstring> CategoryAnimal::easy = {
        L"кот", L"собака", L"лиса", L"утка", L"сова",
        L"лось", L"тигр", L"кит", L"рак", L"лев"
};

const std::vector<std::wstring> CategoryAnimal::medium = {
        L"кенгуру", L"воробей", L"ястреб", L"енот", L"верблюд",
        L"омар", L"зебра", L"барсук", L"питон", L"хомяк"
};

const std::vector<std::wstring> CategoryAnimal::hard = {
        L"аллигатор", L"гиппопотам", L"дельфин", L"коала", L"хамелеон",
        L"носорог", L"мангуст", L"фламинго", L"птеродактиль", L"сурикат"
};

const std::vector<std::wstring> &CategoryAnimal::getLevel(const std::wstring &level) {
    if (level == L"easy") {
        return easy;
    } else if (level == L"medium") {
        return medium;
    } else {
        return hard;
    }
}