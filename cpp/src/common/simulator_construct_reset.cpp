#include "simulator.h"


Simulator::Simulator(int board_edge_len, double knight_probability) {
    sigma = 0;
    sigma_calc = SigmaCalculator();
    board = Board(board_edge_len, knight_probability);
}

void Simulator::full_reset() {
    board.reset_board();
    sigma = 0;
    sigma_calc.reset_vals();
}
