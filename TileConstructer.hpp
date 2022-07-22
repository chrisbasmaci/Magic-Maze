#ifndef AE42CD9D_D00F_468F_9343_4EC10649C2F1
#define AE42CD9D_D00F_468F_9343_4EC10649C2F1

// -----------------------------------------------------------------------------------------//
// ------ Constructer Factory for Tiles which auto decides the derivation to use ----------//
// ------ Room calls Tile constructer in its constructer to fill its 5x5 array  ----------//
// --------------------------------------------------------------------------------------//

#include "FieldTypeFactory.hpp"
class TileConstructer
{
private:
    std::map<std::string, std::unique_ptr<FieldTypeFactory>> Field;
    std::string checkID(const char id);

public:
    // constructer
    TileConstructer();
    // methods
    std::unique_ptr<Tile> constructTile(const char id);
};

#endif /* AE42CD9D_D00F_468F_9343_4EC10649C2F1 */
