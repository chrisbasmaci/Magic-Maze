#ifndef _CHARACTER_CLASS_HPP_
#define _CHARACTER_CLASS_HPP_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

enum class CharacterType
{
    INVALID = 'I',
    FIGHTER_TYPE = 'F',
    THIEF_TYPE = 'T',
    SEER_TYPE = 'S'
};

class Character
{
    // attributes
public:
    CharacterType type_;

public:
    // Constructor
    Character() = delete;
    Character(const Character &) = delete;
    Character(CharacterType type)
    {
        type_ = type;
    }

    // Destruktor
    ~Character() = default;
    // getters

    // ...

    // methods
    CharacterType getCharacterType() { return type_; };
    char getCharacterChar();
};

class A
{
};

#endif
