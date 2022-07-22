#ifndef _ROOM_CLASS_HPP_
#define _ROOM_CLASS_HPP_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <array>

#include "Tile_Class.hpp"

class Room
{
    // attributes
protected:
    static int const map_rows = 5;
    static int const map_cols = 5;

public:
    typedef std::array<std::unique_ptr<Tile>, map_cols> row_type;
    typedef std::array<row_type, map_rows> array_type;

protected:
    char room_id_;
    std::string room_info_str_;
    array_type room_map_ = {{{NULL}}};
    bool revealed_;

public:
    // Constructor
    Room() = delete;
    // : room_id_(room_id), revealed_(false)
    Room(const char &room_id, const std::string &room_info_str);
    // Destruktor
    ~Room() = default;
    // getters
    char getRoomID() { return room_id_; };
    array_type &getRoomMap() { return room_map_; };

    bool getRoomRevealed() { return revealed_; };
    void printRowTop(int row_no);
    void printRowMid(int row_no);
    void printRowBot(int row_no);
    void placeCharacter(int row_to_place, int col_to_place, CharacterType type);
};

#endif