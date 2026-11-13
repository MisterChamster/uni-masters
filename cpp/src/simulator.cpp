#include "simulator.h"


Simulator::Simulator(int board_edge_len, double knight_probability) {
    board = Board(board_edge_len, knight_probability);
}

Board* Simulator::get_board_ptr() {
    return &board;
}
