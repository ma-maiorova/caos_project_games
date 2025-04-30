#include "Render.h"

#include <iomanip>
#include <stdlib.h>
#include <cstdlib>

void Render::ClearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Render::RenderMainMenu(const Menu& menu) {
    ClearScreen();

    PrintColoredString(constants::kColorBlue, "=== МОРСКОЙ БОЙ ===");

    const auto& items = menu.GetItems();
    for (int i = 0; i < items.size(); ++i) {
        if (i == menu.GetSelectedIndex()) {
            std::cout << constants::kColorGreen << constants::kSelector << " " << items[i]
                      << constants::kColorReset << "\n";
        } else {
            std::cout << "  " << items[i] << "\n";
        }
    }

    std::cout << "\nИспользуйте стрелки для выбора, Enter для подтверждения\n";
}

void Render::RenderRules() {
    ClearScreen();

    PrintColoredString(constants::kColorCyan, "=== ПРАВИЛА ИГРЫ ===");
    std::cout << "1. Каждый игрок расставляет свои корабли на поле 10x10\n";
    std::cout << "2. Корабли не могут соприкасаться друг с другом (должен быть зазор хотя бы в одну ячейку)\n";
    std::cout << "3. В свой ход игрок делает выстрел по полю противника\n";
    std::cout << "4. Если выстрел попадает в корабль, игрок продолжает ход\n";
    std::cout << "5. Игра продолжается, пока все корабли одного из игроков не будут уничтожены\n\n";
    std::cout << "Нажмите Enter для возврата в меню...\n";
}

void Render::RenderShipPlacement(Player& player, const std::vector<int>& remaining_ships,
                                 int cursor_x, int cursor_y, bool is_placing,
                                 const Board& temp_board) {
    ClearScreen();

    std::cout << "Расстановка кораблей (" << player.GetName() << ")\n\n";

    std::cout << "Осталось разместить:\n";
    for (int i = 0; i < constants::kShipCounts.size(); ++i) {
        std::cout << remaining_ships[i] << " x " << (i + 1) << "-палубных\n";
    }
    std::cout << "\n";

    std::cout << "Ваше поле:\n";
    PrintBoard(player.GetOwnBoard(), true, true, cursor_x, cursor_y, temp_board);

    std::cout << "\nУправление:\n";
    std::cout << "Стрелки - перемещение курсора\n";
    std::cout << "Пробел - поставить часть корабля\n";
    std::cout << "Enter - завершить корабль\n";
    std::cout << "Delete - удалить корабль\n";
    std::cout << "Y - подтвердить расстановку\n";
    std::cout << "Q - скрыть / показать поле\n";
}

void Render::RenderBattle(Player& current_player, int cursor_x, int cursor_y, const std::string& attack_status) {
    ClearScreen();

    std::cout << "Ход игрока: " << current_player.GetName() << "\n\n";

    std::cout << "Ваше поле:\n";
    PrintBoard(current_player.GetOwnBoard());

    std::cout << "\nПоле противника:\n";
    PrintBoard(current_player.GetEnemyBoard(), false, true,  cursor_x, cursor_y);

    std::cout << "\n" << attack_status << '\n';

    std::cout << "\nЛегенда:\n";
    PrintCursor();
    std::cout << " - курсор\n";
    PrintHitCell();
    std::cout << " - попадание\n";
    PrintSunkShipCell();
    std::cout << " - корабль потоплен\n";
    PrintMissCell();
    std::cout << " - промах\n";
    PrintShipCell();
    std::cout << " – ваш корабль\n";
    PrintEmptyCell();
    std::cout << " - пустая клетка\n";

    std::cout << "\nУправление:\n";
    std::cout << "Стрелки - перемещение курсора\n";
    std::cout << "Пробел - выстрел\n";
    std::cout << "Q - скрыть/показать поле\n";
}

void Render::RenderSwitching(const Player& next_player) {
    ClearScreen();
    PrintColoredString(constants::kColorCyan, "=== СМЕНА ИГРОКА ===");
    std::cout << "Следующий ход: " << next_player.GetName() << "\n\n";
    std::cout << "Подготовьтесь к своему ходу...\n";
    std::cout << "Нажмите Enter, чтобы продолжить\n";
}

void Render::RenderGameOver(Player& winner, const std::string& looser_name) {
    ClearScreen();

    PrintColoredString(constants::kColorCyan, "=== ИГРА ОКОНЧЕНА ===");

    // Поле игрока
    std::cout << "Поле " << winner.GetName() << "\n";
    PrintBoard(winner.GetOwnBoard(), false);

    std::cout << "\nПоле " << looser_name << "\n";
    PrintBoard(winner.GetEnemyBoard(), false);

    std::cout << "\n";
    std::cout << "Победитель: " << winner.GetName() << "!\n\n";
    std::cout << "Нажмите Enter для возврата в меню...\n";
}

void Render::PrintBoard(const Board& board, bool own_board,  bool show_cursor, int cursor_x, int cursor_y, const Board& temp_board) {
    PrintHeaderBoardLine();
    for (int i = 0; i < constants::kBoardSize; ++i) {
        std::cout << i << " ";
        
        for (int j = 0; j < constants::kBoardSize; ++j) {

            if (board.IsHidden()) {
                PrintEmptyCell();
                std::cout << " ";
                continue;
            }

            if (show_cursor && i == cursor_x && j == cursor_y) {
                PrintCursor();
                std::cout << " ";
                continue;
            }

            if (board.IsCellHit(i, j)) {
                PrintHitCell();
            } else if (board.IsCellSunk(i, j)) {
                PrintSunkShipCell();
            } else if (temp_board.IsTempShipCell(i, j)) {
                PrintTempShipCell();
            } else if (board.IsCellMiss(i, j)) {
                PrintMissCell();
            } else if (own_board && board.IsCellShip(i, j)) {
                PrintShipCell();
            } else {
                PrintEmptyCell();
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }
}