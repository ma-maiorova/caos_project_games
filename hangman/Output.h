#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <set>

class Output {
private:
    static const std::vector<std::wstring> Gallow;

public:
    void printWord(const std::wstring &word) const;

    void printErrors(int errors, int lives) const;

    void printCorrectLetters(const std::set<wchar_t> &cur) const;

    void printErrorLetters(const std::set<wchar_t> &cur) const;

    void printGallow(int step, int lives) const;
};
