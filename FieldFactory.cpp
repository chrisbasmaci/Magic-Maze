#include "FieldFactory.hpp"

// Basic###########################################################
// Wall
std::string Wall::getFieldString()
{
    std::string str = "███████\n███████\n███████";

    return str;
};
// Passage
std::string Passage::getFieldString()
{
    std::string str = "       \n       \n       ";

    return str;
}

// Magic###########################################################
// HiddenDoor
std::string HiddenDoor::getFieldString()
{
    std::string str = "███████\n███████\n███████";

    return str;
}
// Monster
std::string Monster::getFieldString()
{
    std::string str = "       \n   M   \n       ";

    return str;
}
// SandClock
std::string SandClock::getFieldString()
{
    std::string str = " \\   / \n  | |  \n /   \\ ";

    return str;
}
// CrystallBall
std::string CrystallBall::getFieldString()
{
    std::string str = "  / \\  \n |   | \n  \\ /  ";

    return str;
}
// HorizontalDoor
std::string HorizontalDoor::getFieldString()
{
    std::string str = "███████\n       \n       ";

    return str;
}
// VerticalDoor
std::string VerticalDoor::getFieldString()
{
    std::string str = "   █   \n   █   \n   █   ";

    return str;
}
// Treasure
std::string Treasure::getFieldString()
{
    std::string str = "$$$$$$$\n$     $\n$$$$$$$";

    return str;
}
// SwitchThief
std::string SwitchThief::getFieldString()
{
    std::string str = "TTTTTTT\nT     T\nTTTTTTT";

    return str;
}
// SwitchWarrior
std::string SwitchWarrior::getFieldString()
{
    std::string str = "FFFFFFF\nF     F\nFFFFFFF";

    return str;
}
// SwitchFortuneTeller
std::string SwitchFortuneTeller::getFieldString()
{
    std::string str = "SSSSSSS\nS     S\nSSSSSSS";

    return str;
}
