#ifndef FieldPrinter_HPP_
#define FieldPrinter_HPP_

#include <map>
#include <memory>
#include "FieldFactory.hpp"

class FieldPrinter
{
    std::map<TileType, std::unique_ptr<FieldFactory>> field_factories;

public:
    FieldPrinter()
    {
        field_factories[TileType::WAND] = std::make_unique<Wall>();
        field_factories[TileType::GANG] = std::make_unique<Passage>();
        field_factories[TileType::GEHEIME_TUR] = std::make_unique<HiddenDoor>();
        field_factories[TileType::MONSTER] = std::make_unique<Monster>();
        field_factories[TileType::SANDUHR] = std::make_unique<SandClock>();
        field_factories[TileType::KRISTALLKUGEL] = std::make_unique<CrystallBall>();
        field_factories[TileType::TUR_HORIZONTAL] = std::make_unique<HorizontalDoor>();
        field_factories[TileType::TUR_VERTIKAL] = std::make_unique<VerticalDoor>();
        field_factories[TileType::SCHATZ] = std::make_unique<Treasure>();
        field_factories[TileType::SCHALTER_DIEB] = std::make_unique<SwitchThief>();
        field_factories[TileType::SCHALTER_KRIEGER] = std::make_unique<SwitchWarrior>();
        field_factories[TileType::SCHALTER_WAHRSAGER] = std::make_unique<SwitchFortuneTeller>();
    }

    std::string pickField(TileType type)
    {
        auto field = field_factories[type]->getFieldString();
        return field;
    }
};
#endif /* A0659E4A_557D_4839_8B7E_41B8968BD180 */
