#include "Character_Class.hpp"

char Character::getCharacterChar()
{
    switch (type_)
    {
    case CharacterType::FIGHTER_TYPE:
        return 'F';

    case CharacterType::THIEF_TYPE:

        return 'T';

    case CharacterType::SEER_TYPE:
        return 'S';

    default:
        return ' ';
    }
    return static_cast<std::underlying_type<CharacterType>::type>(type_);
    return 'a';
}
