#include "PrintUtils.hpp"

void PrintUtils::printHorizontalBorder(int cols)
{
    std::string full_border;
    full_border += cross_symbol;

    for (size_t _ = 0; _ < cols; _++)
    {
        full_border += border_top;
        full_border += cross_symbol;
    }
    std::cout << full_border << std::endl;
};

void printTL(std::string mid_row, char id)
{
    mid_row.at(2) = id;
    std::cout << mid_row;
}