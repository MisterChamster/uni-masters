#include "simulator.h"


Simulator::Simulator() {
    board = Board();
    sigma = 0;
    sigma_calc = SigmaCalculator();
}

Simulator::Simulator(int board_edge_len, double knight_probability) {
    initialize(board_edge_len, knight_probability);
}

void Simulator::initialize(int board_edge_len, double knight_probability) {
    board = Board(board_edge_len, knight_probability);
    sigma = 0;
    sigma_calc = SigmaCalculator();
}

void Simulator::full_reset() {
    board.reset_board();
    sigma = 0;
    sigma_calc.reset_vals();
}

void Simulator::reconstruct(int board_edge_len, double knight_probability) {
    full_reset();
    initialize(board_edge_len, knight_probability);
}
