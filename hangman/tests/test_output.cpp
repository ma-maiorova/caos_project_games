#include <gtest/gtest.h>
#include <sstream>
#include "../Output.h"

struct WStreamRedirect {
    WStreamRedirect(std::wostream &out, std::wstreambuf *newBuf)
            : out(out), oldBuf(out.rdbuf(newBuf)) {}

    ~WStreamRedirect() { out.rdbuf(oldBuf); }

private:
    std::wostream &out;
    std::wstreambuf *oldBuf;
};

TEST(OutputTest, PrintWord) {
    Output out;
    std::wstringstream ss;
    WStreamRedirect rd(std::wcout, ss.rdbuf());

    out.printWord(L"t__t");
    EXPECT_EQ(ss.str(), L"Сейчас слово выглядит так: t__t\n");
}

TEST(OutputTest, PrintErrors) {
    Output out;
    std::wstringstream ss;
    WStreamRedirect rd(std::wcout, ss.rdbuf());

    out.printErrors(2, 4);
    EXPECT_EQ(ss.str(), L"Уже было 2 попыток, осталось 4\n");
}

TEST(OutputTest, PrintCorrectAndErrorLetters) {
    Output out;
    std::wstringstream ss;
    WStreamRedirect rd(std::wcout, ss.rdbuf());

    std::set<wchar_t> correct = {L'a', L'b'};
    std::set<wchar_t> wrong = {L'x', L'y'};

    out.printCorrectLetters(correct);
    out.printErrorLetters(wrong);

    std::wstring expected =
            L"Угаданные буквы: a b \n"
            L"Неправильные буквы: x y \n";
    EXPECT_EQ(ss.str(), expected);
}

TEST(OutputTest, PrintGallow_DefaultStep) {
    Output out;
    std::wstringstream ss;
    WStreamRedirect rd(std::wcout, ss.rdbuf());

    out.printGallow(2, 5);
    EXPECT_TRUE(ss.str().find(L"O   |\n  |   |") != std::wstring::npos);
}

TEST(OutputTest, PrintGallow_LastWhenStepEqualsLives) {
    Output out;
    std::wstringstream ss;
    WStreamRedirect rd(std::wcout, ss.rdbuf());

    out.printGallow(4, 4);
    EXPECT_TRUE(ss.str().find(L"/ \\  |") != std::wstring::npos);
}
