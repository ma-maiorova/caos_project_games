#include "Game.h"
#include "InputHandler.h"
#include "Render.h"

#include <algorithm>
#include <unistd.h>

Game::Game()
    : state_(constants::MAIN_MENU),
      main_menu_({"Начать игру", "Правила"}),
      player1_("Игрок 1"),
      player2_("Игрок 2"),
      current_player_(&player1_),
      other_player_(&player2_) {

    std::shared_ptr<Board> player1_board = std::make_shared<Board>();
    std::shared_ptr<Board> player2_board = std::make_shared<Board>();

    player1_.SetMyBoard(player1_board);
    player1_.SetEnemyBoard(player2_board);

    player2_.SetMyBoard(player2_board);
    player2_.SetEnemyBoard(player1_board);

    InputHandler::Init();
}

void Game::Run() {
    while (state_ != constants::EXIT) {
        switch (state_) {
            case constants::MAIN_MENU:
                ProcessMainMenu();
                break;
            case constants::SHIP_PLACEMENT:
                ProcessShipPlacement();
                break;
            case constants::BATTLE:
                ProcessBattle();
                break;
            case constants::SWITCHING:
                ProcessSwitching();
                break;
            case constants::GAME_OVER:
                ResetGame();
                break;
            case constants::EXIT:
                break;
        }
    }
    InputHandler::Cleanup();
}

void Game::SwitchPlayer() {
    std::swap(current_player_, other_player_);
}

void Game::ProcessMainMenu() {
    Render::RenderMainMenu(main_menu_);

    int input;
    while (1) {

        while ((input = InputHandler::GetInput()) == 0) {
        }
        // std::cout << input << '\n';
        if (input == constants::kArrowUp) {
            // Up
            main_menu_.MoveUp();
            break;

        } else if (input == constants::kArrowDown) {
            // Down
            main_menu_.MoveDown();
            break;

        } else if (input == constants::kEnter) {
            // Enter
            if (main_menu_.GetSelectedIndex() == 0) {
                state_ = constants::SHIP_PLACEMENT;
                return;
            } else {
                Render::RenderRules();
                InputHandler::WaitForEnter();
                break;
            }

        } else if (input == constants::kEscape) {
            // Escape
            state_ = constants::EXIT;
            return;
        }
    }
}

void Game::ProcessShipPlacement() {
    std::vector<int> remaining_ships = constants::kShipCounts;
    std::vector<std::pair<int, int>> current_ship_cells;
    int cursor_x = 0, cursor_y = 0;
    bool placing = false;
    int input;

    while (true) {
        auto temp_board = current_player_->GetOwnBoard();
        for (const auto& cell : current_ship_cells) {
            temp_board.SetTempShipCell(cell.first, cell.second);
        }

        Render::RenderShipPlacement(*current_player_, remaining_ships, cursor_x, cursor_y, placing,
                                    temp_board);

        while ((input = InputHandler::GetInput()) == 0) {
        }

        switch (input) {
            case constants::kArrowUp:
                cursor_x = std::max(0, cursor_x - 1);
                break;

            case constants::kArrowDown:
                cursor_x = std::min(cursor_x + 1, constants::kBoardSize - 1);
                break;

            case constants::kArrowRight:
                cursor_y = std::min(cursor_y + 1, constants::kBoardSize - 1);
                break;

            case constants::kArrowLeft:
                cursor_y = std::max(cursor_y - 1, 0);
                break;

            case constants::kEscape:
                state_ = constants::EXIT;
                return;

            case constants::kSpace:
                // Поставить часть корабля
                if (!placing && current_player_->GetOwnBoard().IsCellEmpty(cursor_x, cursor_y)) {
                    current_ship_cells.emplace_back(cursor_x, cursor_y);
                    placing = true;

                } else if (placing) {
                    // Проверяем, что клетка соседняя с уже поставленными
                    bool adjacent = false;
                    for (const auto& cell : current_ship_cells) {
                        if ((abs(cell.first - cursor_x) == 1 && cell.second == cursor_y) ||
                            (abs(cell.second - cursor_y) == 1 && cell.first == cursor_x)) {
                            adjacent = true;
                            break;
                        }
                    }

                    if (adjacent &&
                        current_player_->GetOwnBoard().IsCellEmpty(cursor_x, cursor_y)) {
                        current_ship_cells.emplace_back(cursor_x, cursor_y);
                    }
                }
                break;

            case constants::kEnter:
                if (placing && !current_ship_cells.empty()) {
                    int ship_size = current_ship_cells.size();
                    if (ship_size <= constants::kShipCounts.size() &&
                        remaining_ships[ship_size - 1] > 0) {
                        if (current_player_->GetOwnBoard().PlaceShip(current_ship_cells)) {
                            remaining_ships[ship_size - 1]--;
                        }
                    }
                    current_ship_cells.clear();
                    placing = false;
                }
                break;

            case constants::kDelete:
                current_player_->GetOwnBoard().RemoveShip(cursor_x, cursor_y);
                current_ship_cells.clear();
                placing = false;

                // Обновляем оставшиеся корабли
                remaining_ships = constants::kShipCounts;
                for (const auto& ship : current_player_->GetOwnBoard().GetShips()) {
                    int size = ship->GetSize();
                    if (size <= remaining_ships.size()) {
                        remaining_ships[size - 1]--;
                    }
                }
                break;

            case 'y':
                // Подтвеждение расстановки
                if (std::all_of(remaining_ships.begin(), remaining_ships.end(),
                                [](int count) { return count == 0; })) {
                    SwitchPlayer();
                    if (current_player_ == &player1_) {
                        state_ = constants::BATTLE;
                    }
                    return;
                }
                break;

            case 'q':
                // спрятать / показать поле
                current_player_->GetOwnBoard().ShowHide();
                break;
        }
    }
}

void Game::ProcessBattle() {
    int cursor_x = 0, cursor_y = 0;
    bool hit = true;
    int input;
    std::string attack_status = " ";

    while (1) {
        Render::RenderBattle(*current_player_, cursor_x, cursor_y, attack_status);

        while ((input = InputHandler::GetInput()) == 0) {
        }

        switch (input) {
            case constants::kArrowUp:
                cursor_x = std::max(0, cursor_x - 1);
                break;

            case constants::kArrowDown:
                cursor_x = std::min(cursor_x + 1, constants::kBoardSize - 1);
                break;

            case constants::kArrowRight:
                cursor_y = std::min(cursor_y + 1, constants::kBoardSize - 1);
                break;

            case constants::kArrowLeft:
                cursor_y = std::max(cursor_y - 1, 0);
                break;

            case constants::kSpace:
                // выстрел

                // проверка, что стреляем по свежей ячейке
                if (!current_player_->GetEnemyBoard().IsCellHit(cursor_x, cursor_y) &&
                    !current_player_->GetEnemyBoard().IsCellMiss(cursor_x, cursor_y)) {
                    // hit returns true if the attack was succesful
                    hit =
                        current_player_->GetEnemyBoard().Attack(cursor_x, cursor_y, attack_status);

                    if (other_player_->GetOwnBoard().AllShipsSunk()) {
                        state_ = constants::GAME_OVER;
                        return;
                    }
                }
                break;

            case constants::kEnter:
                if (!hit) {
                    SwitchPlayer();
                    state_ = constants::SWITCHING;
                    return;
                }

            case 'q':
                // спрятать / показать поле
                current_player_->GetOwnBoard().ShowHide();
                break;
        }
    }
}

void Game::ProcessSwitching() {
    Render::RenderSwitching(*current_player_);
    InputHandler::WaitForEnter();
    state_ = constants::BATTLE;
}

void Game::ResetGame() {
    Render::RenderGameOver(*current_player_, other_player_->GetName());

    player1_.Reset();
    player2_.Reset();
    current_player_ = &player1_;
    other_player_ = &player2_;
    state_ = constants::MAIN_MENU;

    InputHandler::WaitForEnter();
}