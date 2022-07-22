#ifndef _TILE_CLASS_HPP_
#define _TILE_CLASS_HPP_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

#include "Character_Class.hpp"

enum class TileType
{
    WAND = 'W',
    GANG = 'P',
    GEHEIME_TUR = 'X',
    MONSTER = 'M',
    SANDUHR = 'G',
    KRISTALLKUGEL = 'C',
    TUR_HORIZONTAL = 'H',
    TUR_VERTIKAL = 'V',
    SCHATZ = 'L',
    SCHALTER_DIEB = 'T',
    SCHALTER_KRIEGER = 'F',
    SCHALTER_WAHRSAGER = 'S'
};

class Tile
{
    // attributes
protected:
    std::shared_ptr<Character> character_;
    bool character_set_;
    char tile_id_;
    bool is_accessible_;
    bool is_trespassable_;
    bool is_changeable_;

public:
    // Constructor
    Tile() = delete;
    Tile(char tile_id);
    // Destruktor
    virtual ~Tile() = default;
    // getters

    // ...

    // methods
    virtual std::string getTileString(bool revealed) const = 0;
    // void placeTileId();
    std::string getTileStringTop(bool revealed);
    std::string getTileStringMid(bool revealed);
    std::string getTileStringBot(bool revealed);
    void setCharacter(std::shared_ptr<Character> character)
    {
        character_ = character;
        // character_ = std::move(character);
        character_set_ = 1;
    }
    char getTileId() { return tile_id_; }
};

#endif