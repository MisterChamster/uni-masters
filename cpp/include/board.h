#pragma once

#include "board_node.h"
#include "knight.h"


class Board {
private:
    int edge_len;
    std::vector<BoardNode> board_fields;
    std::vector<Knight*> knights;

    void EXAMPLEfill_board_fields();

public:
    Board(int len);

    void print_board();
};
