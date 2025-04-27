#pragma once

#include <string>
#include <algorithm>
#include <cwctype>

inline void trim_ws(std::wstring &s) {
    while (!s.empty() && (s.back() == L'\r' || s.back() == L'\n' || std::iswspace(s.back())))
        s.pop_back();
    while (!s.empty() && std::iswspace(s.front()))
        s.erase(s.begin());
}