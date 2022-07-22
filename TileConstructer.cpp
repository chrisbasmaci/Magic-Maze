#include "TileConstructer.hpp"

TileConstructer::TileConstructer()
{
    Field["basic"] = std::make_unique<BasicFieldFactory>();
    Field["magic"] = std::make_unique<MagicFieldFactory>();
}

std::string TileConstructer::checkID(const char id)
{
    // std::cout << id << std::endl;
    switch (id)
    {
        // basic tile types
    case char(TileType::WAND):
    case char(TileType::GANG):
        return "basic";
        // basic magic types
    case char(TileType::GEHEIME_TUR):
    case char(TileType::MONSTER):
    case char(TileType::SANDUHR):
    case char(TileType::KRISTALLKUGEL):
    case char(TileType::TUR_HORIZONTAL):
    case char(TileType::TUR_VERTIKAL):
    case char(TileType::SCHATZ):
    case char(TileType::SCHALTER_DIEB):
    case char(TileType::SCHALTER_KRIEGER):
    case char(TileType::SCHALTER_WAHRSAGER):
        return "magic";
    default:
        return "unimplimented";
    }
    return "unimplimented";
}

std::unique_ptr<Tile> TileConstructer::constructTile(const char id)
{
    // TileType type = static_cast<TileType>(id);
    std::string tile_type = checkID(id);

    // add exception class
    if (tile_type == "unimplimented")
    {
        std::cout << id;
        std::cout << "EXITTED" << std::endl;
        std::exit(1);
    }

    return Field[tile_type]->createField(id);
}