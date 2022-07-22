#include "ParseCommando.hpp"
#include "RoomInfo.hpp"
#include <algorithm>

#include <iostream>

ParseCommando::ParseCommando(int argc, std::vector<std::string> argv_vec)
{
    // std::vector<std::string> rows_vec;
    bool is_correctly_inputted = true;
    bool s_exists = false;
    bool first = true;
    size_t row_element = 0;

    for (const auto &row : argv_vec)
    {
        if (argv_vec.empty())
        {
            throw WrongCommandoArgsException();
        }

        // rows_vec.push_back(row);

        // max 5 rooms in one row
        is_correctly_inputted = (row.size() > 5) ? is_correctly_inputted = false : is_correctly_inputted;

        // Check if rows are all equal length
        if (!first)
        {
            is_correctly_inputted = (row_element != row.size()) ? false : is_correctly_inputted;
        }
        row_element = row.size();
        first = false;
        // ------------------------------------------------------------------------------------

        for (const auto &c : row)
        {

            // Check if room exists
            is_correctly_inputted = (c > 'Z' || c < 'A') ? false : is_correctly_inputted;

            // Check if room has data
            std::string room_info_str = Oop::RoomInfo::getInstance().getRoomInfoString(c);
            is_correctly_inputted = (room_info_str.size() != 25) ? false : is_correctly_inputted;

            // fill roomid vec
            is_correctly_inputted = (std::count(room_id_vec_.begin(), room_id_vec_.end(), c) != 0) ? false : is_correctly_inputted;
            room_id_vec_.push_back(c);
            // fill roominfo vec
            room_info_vec_.push_back(room_info_str);

            // Check if every char is uppercase
            is_correctly_inputted = (!isupper(c)) ? false : is_correctly_inputted;
            // Check if starting card exists
            s_exists = (c == 'S') ? true : s_exists;
        }
    }
    if (!s_exists || !is_correctly_inputted)
    {
        throw WrongCommandoArgsException();
    };

    // initialise attributes if all gucci
    row_total_ = argc - 1;
    col_total_ = row_element;
}
