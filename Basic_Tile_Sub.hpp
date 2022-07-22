#ifndef _BASIC_TILE_SUB_HPP_
#define _BASIC_TILE_SUB_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "Tile_Class.hpp"
#include "FieldPrinter.hpp"

// TileType::WAND,
// TileType::GANG,
class BasicTile : public Tile
{
public:
    // inherit the base konstruktor
    using Tile::Tile;

    // MagicTile(const MagicTile &) = delete;
    ~BasicTile() = default;

    // Methods
    std::string getTileString(bool revealed) const override;
};

#endif
