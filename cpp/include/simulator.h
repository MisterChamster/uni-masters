#pragma once

#include "board.h"

class Simulator {
public:
// private:
    Board board;


public:
    Simulator(int board_edge_len, double knight_probability);
    Board* get_board_ptr();
};
