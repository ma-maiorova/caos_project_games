#include "CategoryFood.h"

const std::vector<std::wstring> CategoryFood::easy = {
        L"яблоко", L"груша", L"банан", L"морковь", L"слива",
        L"персик", L"арбуз", L"лук", L"помидор", L"вишня"
};

const std::vector<std::wstring> CategoryFood::medium = {
        L"ананас", L"манго", L"дыня", L"баклажан", L"лимон",
        L"грейпфрут", L"абрикос", L"огурец", L"чеснок", L"капуста"
};

const std::vector<std::wstring> CategoryFood::hard = {
        L"папайя", L"маракуйя", L"авокадо", L"редиска", L"брокколи",
        L"свекла", L"киви", L"хурма", L"гранат", L"артишок"
};

const std::vector<std::wstring> &CategoryFood::getLevel(const std::wstring &level) {
    if (level == L"easy") {
        return easy;
    } else if (level == L"medium") {
        return medium;
    } else {
        return hard;
    }
}
