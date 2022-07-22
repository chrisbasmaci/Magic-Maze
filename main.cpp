#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include <string>
#include <map>
#include <algorithm>

#include "RoomInfo.hpp"
#include "Tile_Class.hpp"
#include "Basic_Tile_Sub.hpp"
#include "TileConstructer.hpp"
#include "Room_Class.hpp"
#include "PrintUtils.hpp"
#include "ParseCommando.hpp"
#include "Game_Class.hpp"
#include "Random.hpp"

// using Oop::RoomInfo;
// char room_id = 'A';
// std::string str;
// str = Oop::RoomInfo::getInstance().getRoomInfoString(room_id);
int main(int argc, char **argv)
{


    std::vector<std::string> rows_vec;

    // argv to vector skip ./a2
    std::vector<std::string> argList(argv + 1, argv + argc);

    std::unique_ptr<ParseCommando> Parser;
    try
    {
        Parser = std::make_unique<ParseCommando>(argc, argList);
        // rows_vec = P.getRows();
    }
    catch (const WrongCommandoArgsException &ex)
    {
        std::cout << "Error: Invalid configuration!" << std::endl;
        return 2;
    }
    // Game begins------------------------------------------------------

    Game &GAME = Game::instance(Parser->getRowTotal(), Parser->getColTotal());
    GAME.fillRooms(Parser->getRoomIdsVec(), Parser->getRoomInfoStringsVec());

    //place the starting chars
    GAME.placePlayers(1, 1, CharacterType::FIGHTER_TYPE, 'S');
    GAME.placePlayers(1, 3, CharacterType::THIEF_TYPE, 'S');
    GAME.placePlayers(3, 1, CharacterType::SEER_TYPE, 'S');

//    GAME.displayRooms();
    GAME.beginInputLoop();

    return 0;
}