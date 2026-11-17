#include <iostream>

#include "simulator.h"


void Simulator::simulate_sigma_over_time(int board_edge_len, int moves_count, int forget_after_N_steps, float forgetting_factor, std::filesystem::path save_path) {
    double knight_probabilities[4] = {0.25, 0.5, 0.75, 1.0};

    for (int i=0; i<4; i++) {
        double curr_prob = knight_probabilities[i];
        std::string data_name = "p = " + std::to_string(curr_prob);

        initialize(board_edge_len, curr_prob);
        move_all_knights_n_out_sigmas(
            moves_count,
            forget_after_N_steps,
            forgetting_factor,
            save_path,
            data_name);
        full_reset();
    }
}
