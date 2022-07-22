#ifndef PRINTUTILS_HPP
#define PRINTUTILS_HPP

#include <string>
#include <vector>
#include <iostream>
#include <array>
#include <sstream>
#include <memory>
#include "Tile_Class.hpp"

class PrintUtils
{
private:
    std::string cross_symbol = "╬";
    std::string border_symbol = "═";
    std::string vert_border_symbol = "║";

    std::string border_top = "═══════════════════════════════════";
    const int room_width = 7 * 5;

    // PrintUtils();
    // ~PrintUtils() = default;

public:
    void printHorizontalBorder(int cols);
    void printVericalSymbol() { std::cout << vert_border_symbol; };
    void printTL(std::string mid_row, char id);
};

#endif