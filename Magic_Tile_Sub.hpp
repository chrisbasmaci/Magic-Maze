#ifndef _MAGIC_TILE_SUB_HPP_
#define _MAGIC_TILE_SUB_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "Tile_Class.hpp"
#include "FieldPrinter.hpp"

class MagicTile : public Tile
{
private:
public:
    // inherit the base konstruktor
    using Tile::Tile;

    // MagicTile(const MagicTile &) = delete;
    ~MagicTile() = default;

    // Methods
    std::string getTileString(bool revealed) const override;

    void magicUsed(){}; // implement it
};

#endif
