#include "CategoryCities.h"

const std::vector<std::wstring> CategoryCities::easy = {
        L"париж", L"рим", L"киев", L"минск", L"берлин",
        L"лондон", L"мадрид", L"токио", L"канада", L"сидней"
};

const std::vector<std::wstring> CategoryCities::medium = {
        L"ванкувер", L"стокгольм", L"будапешт", L"афины", L"варшава",
        L"дубай", L"стамбул", L"чикаго", L"вена", L"манила"
};

const std::vector<std::wstring> CategoryCities::hard = {
        L"йоханнесбург", L"кострома", L"копенгаген", L"эдинбург", L"бразилиа",
        L"валлетта", L"лихтенштейн", L"брюссель", L"каракас", L"мале"
};

const std::vector<std::wstring> &CategoryCities::getLevel(const std::wstring &level) {
    if (level == L"easy") {
        return easy;
    } else if (level == L"medium") {
        return medium;
    } else {
        return hard;
    }
}
