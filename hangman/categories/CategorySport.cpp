#include "CategorySport.h"

const std::vector<std::wstring> CategorySport::easy = {
        L"футбол", L"хоккей", L"баскетбол", L"теннис", L"гольф",
        L"волейбол", L"плавание", L"шахматы", L"дзюдо", L"бег"
};

const std::vector<std::wstring> CategorySport::medium = {
        L"фехтование", L"биатлон", L"гимнастика", L"триатлон", L"сноуборд",
        L"регби", L"бокс", L"крикет", L"гребля", L"йога"
};

const std::vector<std::wstring> CategorySport::hard = {
        L"скалолазание", L"сумо", L"паркур", L"автогонки", L"шахматы",
        L"кёрлинг", L"фристайл", L"бодибилдинг", L"ушу", L"прыжки"
};

const std::vector<std::wstring> &CategorySport::getLevel(const std::wstring &level) {
    if (level == L"easy") {
        return easy;
    } else if (level == L"medium") {
        return medium;
    } else {
        return hard;
    }
}
