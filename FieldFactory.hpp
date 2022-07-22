#ifndef BF3759EF_2B99_4B78_8959_AE87D8A04ECA
#define BF3759EF_2B99_4B78_8959_AE87D8A04ECA
#include <map>
#include <memory>
#include "Tile_Class.hpp"

class FieldFactory
{

public:
    virtual ~FieldFactory() = default;

    virtual std::string getFieldString() = 0;
};
// Basic-----------------------------------------------------------------------------
class Wall : public FieldFactory
{
    std::string getFieldString() override;
};

class Passage : public FieldFactory
{
    std::string getFieldString() override;
};

// Magic---------------------------------------------------------------------------
class HiddenDoor : public FieldFactory
{
    std::string getFieldString() override;
};

class Monster : public FieldFactory
{
    std::string getFieldString() override;
};

class SandClock : public FieldFactory
{
    std::string getFieldString() override;
};

class CrystallBall : public FieldFactory
{
    std::string getFieldString() override;
};

class HorizontalDoor : public FieldFactory
{
    std::string getFieldString() override;
};

class VerticalDoor : public FieldFactory
{
    std::string getFieldString() override;
};

class Treasure : public FieldFactory
{
    std::string getFieldString() override;
};

class SwitchThief : public FieldFactory
{
    std::string getFieldString() override;
};

class SwitchWarrior : public FieldFactory
{
    std::string getFieldString() override;
};

class SwitchFortuneTeller : public FieldFactory
{
    std::string getFieldString() override;
};

// -------------------------------------------------------------------------------


#endif /* BF3759EF_2B99_4B78_8959_AE87D8A04ECA */
