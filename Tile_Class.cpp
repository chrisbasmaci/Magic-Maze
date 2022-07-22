#include "Tile_Class.hpp"
#include <sstream>

Tile::Tile(char tile_id) : character_(nullptr), tile_id_(tile_id), character_set_(false)
{
    // PXGCHVLTFS

    is_accessible_ = (tile_id == 'P' || tile_id == 'G' || tile_id == 'C' ||
                      tile_id == 'L' || tile_id == 'T' ||
                      tile_id == 'F' || tile_id == 'S')
                         ? true
                         : false;
    is_trespassable_ = is_accessible_;

    is_changeable_ = (tile_id == 'X' || tile_id == 'V' || tile_id == 'L') ? false : true;
}

std::string Tile::getTileStringTop(bool revealed)
{
    std::string full_str = getTileString(revealed);
    std::string top = "";

    std::istringstream ss(full_str);
    std::string line;
    int row = 0;

    while (std::getline(ss, line, '\n'))
    {
        top = (row == 0) ? line : top;
        row++;
    }
    return top;
}

std::string Tile::getTileStringMid(bool revealed)
{

    std::string full_str = getTileString(revealed);
    std::string mid = "";

    std::istringstream ss(full_str);
    std::string line;
    int row = 0;

    while (std::getline(ss, line, '\n'))
    {
        mid = (row == 1) ? line : mid;
        row++;
    }

    if (character_set_)
    {
        mid.at(3) = character_->getCharacterChar();
    }
    return mid;
}
std::string Tile::getTileStringBot(bool revealed)
{
    std::string full_str = getTileString(revealed);
    std::string bot = "";

    std::istringstream ss(full_str);
    std::string line;
    int row = 0;

    while (std::getline(ss, line, '\n'))
    {
        // std::cout << "row" << row << std::endl;
        bot = (row == 2) ? line : bot;
        row++;
    }
    return bot;
}
// void Tile::placeTileId()
// {

// }