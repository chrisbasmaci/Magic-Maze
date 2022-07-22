#include "Magic_Tile_Sub.hpp"

std::string MagicTile::getTileString(bool revealed) const
{
    if (!revealed)
    {
        return "UUUUUUU\nUUUUUUU\nUUUUUUU";
    }

    FieldPrinter FP;

    std::string field_str = "";
    TileType type = static_cast<TileType>(tile_id_);
    field_str = FP.pickField(type);
    return field_str;
}
