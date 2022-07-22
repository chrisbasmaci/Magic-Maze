#ifndef FE360FCA_149C_4996_AAC5_35E75F03E1BA
#define FE360FCA_149C_4996_AAC5_35E75F03E1BA
#include <string>
#include <vector>
#include <vector>

class ParseCommando
{
private:
    int row_total_;
    int col_total_;
    std::vector<char> room_id_vec_;
    std::vector<std::string> room_info_vec_;

public:
    ParseCommando();
    // : argc_(argc), argv_vec_(argv_vec)
    ParseCommando(int argc, std::vector<std::string> argv_vec);
    // std::vector<std::string> getRoomId_vec(){};
    std::vector<char> getRoomIdsVec() { return room_id_vec_; }
    std::vector<std::string> getRoomInfoStringsVec() { return room_info_vec_; }
    int getRowTotal() { return row_total_; }
    int getColTotal() { return col_total_; }
};

class WrongCommandoArgsException: public std::exception
{
};
#endif /* FE360FCA_149C_4996_AAC5_35E75F03E1BA */
