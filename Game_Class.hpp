#ifndef _GAME_CLASS_HPP_
#define _GAME_CLASS_HPP_
#include <iostream>
#include <iostream>
#include <memory>
#include "Room_Class.hpp"
#include "Character_Class.hpp"


enum class MovementDirection
{
    up = 1,
    right = 2,
    down = 3,
    left =4
};

// need to implement
class Game
{
private:
    const int row_total_;
    const int col_total_;
    const int room_total_;
    int card_flip_counter_;
    int direction_cards_left_;
    MovementDirection direction;


    std::vector<std::unique_ptr<Room>> rooms_vec_;

public:
    static Game &instance(int row, int col)
    {
        static Game instance_(row, col);
        return instance_;
    }
    ~Game() {}
    void displayCardFlipCounter();
    void fillRooms(std::vector<char> room_id, std::vector<std::string> room_info);
    void displayRooms();
    void placePlayers(int row_to_place, int col_to_place, CharacterType type, char room_id);
    void changeDirection();

private:
    Game(const Game &);
    Game &operator=(const Game &);
    Game(int row, int col);
};
#endif