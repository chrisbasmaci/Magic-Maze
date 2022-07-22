#include "Game_Class.hpp"
#include "PrintUtils.hpp"
#include "Random.hpp"
//also get the direction card and set the remaining cards to 3 since we pick one of them
Game::Game(int row, int col) : row_total_(row), col_total_(col), room_total_(col * row),
                                direction(static_cast<MovementDirection>( Oop::Random::getInstance().getRandomCard((4)))),
                                direction_cards_left_(3)
{
    std::cout << "Welcome to the magical OOP1 Maze!!!\n"
              << "Card Flip Counter:   " << card_flip_counter_ << std::endl;
};

void Game::displayCardFlipCounter()
{
    std::cout << "Card Flip Counter:   " << card_flip_counter_ << std::endl;
};

void Game::fillRooms(std::vector<char> room_id, std::vector<std::string> room_info)
{
    int id_no = 0;
    for (auto info : room_info)
    {
        auto room = std::make_unique<Room>(room_id.at(id_no), info);
        rooms_vec_.push_back(std::move(room));
        id_no++;
    }
};

void Game::displayRooms()
{
    int count = 1;
    int row_index = 0;
    int break_index = 0;
    PrintUtils Border;
    Border.printHorizontalBorder(col_total_);
    while (count <= row_total_)
    {
        for (int row = 0; row < 5; row++)
        {
            // std::cout << row << std::endl;

            for (int col = break_index; col < break_index + col_total_; col++)
            {
                if (col < 1 + break_index)
                    Border.printVericalSymbol();

                rooms_vec_.at(col)->printRowTop(row);
                Border.printVericalSymbol();
            }
            std::cout << std::endl;

            // ----------------------------
            for (int col = break_index; col < break_index + col_total_; col++)
            {
                // if (col == 0 && row == 0)
                // {
                //     Border.printVericalSymbol();
                //     continue;
                // }
                if (col < 1 + break_index)
                    Border.printVericalSymbol();

                rooms_vec_.at(col)->printRowMid(row);
                Border.printVericalSymbol();
            }
            std::cout << std::endl;

            for (int col = break_index; col < break_index + col_total_; col++)
            {
                if (col < 1 + break_index)
                    Border.printVericalSymbol();

                rooms_vec_.at(col)->printRowBot(row);
                Border.printVericalSymbol();
            }
            std::cout << std::endl;
        }
        count++;
        break_index += col_total_;
        Border.printHorizontalBorder(col_total_);
    }
    std::cout << std::endl;
}

void Game::placePlayers(int row_to_place, int col_to_place, CharacterType type, char room_id)
{
    for (auto &r : rooms_vec_)
    {
        if (r->getRoomID() == room_id)
            r->placeCharacter(row_to_place, col_to_place, type);
    }
}
void Game::changeDirection()
{
    direction = static_cast<MovementDirection>(Oop::Random::getInstance().getRandomCard((direction_cards_left_)));
    direction_cards_left_ --;
}