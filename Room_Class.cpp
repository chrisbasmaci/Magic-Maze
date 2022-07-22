#include "Room_Class.hpp"
#include "TileConstructer.hpp"
#include "Character_Class.hpp"

Room::Room(const char &room_id, const std::string &room_info_str) : room_id_(room_id), room_info_str_(room_info_str), revealed_(false)
{
    std::cout<<room_info_str<<std::endl;
    // std::cout << "roomid: " << room_id << std::endl;
    // std::cout << "roominfo: " << room_info_str << std::endl;
    TileConstructer TC;
    if(room_id == 'S'){revealed_ = true;}

    int tile_no = 0;


    for (size_t row = 0; row < map_rows; row++)
    {
        for (size_t col = 0; col < map_cols; col++)
        {

            room_map_[row][col] = TC.constructTile(room_info_str.at(tile_no));
            // std::cout << room_map_[map_rows][map_cols]->getTileString
            // std::cout << room_info_str.at(tile_no);
            tile_no++;
        }
        // std::cout << std::endl;
    }
}

void Room::printRowTop(int row_no)
{
    row_type *row = &room_map_[row_no];

    for (size_t i = 0; i < map_cols; i++)
    {
        std::cout << row->at(i)->getTileStringTop(revealed_);
    }
}
void Room::printRowMid(int row_no)
{
    row_type *row = &room_map_[row_no];

    for (size_t i = 0; i < map_cols; i++)
    {
        if (row_no == 0 && i == 0 && revealed_)
        {

            auto str = row->at(i)->getTileStringMid(revealed_);
            char id = row->at(i)->getTileId();
            // str.assign(1, 2) = 'A';

            std::cout << "███" << room_id_ << "███";

            // str[3] = 'A';
            // std::cout << str;
            continue;
        }
        else
            std::cout << row->at(i)->getTileStringMid(revealed_);
    }
}

void Room::printRowBot(int row_no)
{
    row_type *row = &room_map_[row_no];

    for (size_t i = 0; i < map_cols; i++)
    {
        std::cout << row->at(i)->getTileStringBot(revealed_);
    }
}

void Room::placeCharacter(int row_to_place, int col_to_place, CharacterType type)
{
    std::shared_ptr<Character> CHARACTER;

    CHARACTER = std::make_shared<Character>(type);
    for (size_t row = 0; row < map_rows; row++)
    {
        for (size_t col = 0; col < map_cols; col++)
        {
            room_map_[row_to_place][col_to_place]->setCharacter(CHARACTER);
        }
        // std::cout << std::endl;
    }
}