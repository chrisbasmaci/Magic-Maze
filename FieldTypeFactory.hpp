#ifndef _FIELDTYPEFACTORY_HPP_
#define _FIELDTYPEFACTORY_HPP_
#include <memory>
#include <string>
#include <vector>
#include "Tile_Class.hpp"
#include "Magic_Tile_Sub.hpp"
#include "Basic_Tile_Sub.hpp"

// ------------------------------------------------------------------------//
// ----- A Factory to encupsulate the different types of Fields------------//
// ------------------------------------------------------------------------//

class FieldTypeFactory
{
public:
    virtual ~FieldTypeFactory() = default;

    virtual std::unique_ptr<Tile> createField(char id) = 0;
};

class MagicFieldFactory : public FieldTypeFactory
{

public:
    std::unique_ptr<Tile> createField(char id) override
    {
        return std::make_unique<MagicTile>(id);
    }
};

class BasicFieldFactory : public FieldTypeFactory
{

public:
    std::unique_ptr<Tile> createField(char id) override
    {
        return std::make_unique<BasicTile>(id);
    }
};

#endif /* FieldPicker */
