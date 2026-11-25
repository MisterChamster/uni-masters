#include <iostream>

#include "simulator.h"
#include "file_ops.h"
#include "utils.h"
#include "config.hpp"


void Simulator::simulate_sigma_over_time(
        int board_edge_len,
        int turns_count,
        int forget_after_N_turns,
        float forgetting_factor,
        std::filesystem::path project_path,
        int omit_sigma_turns) {
    double knight_probabilities[4] = {0.25, 0.5, 0.75, 1.0};
    std::string file_ext = config::SOT_FILE_EXT;

    std::filesystem::path save_dir = create_and_get_sot_simulation_dir(project_path, board_edge_len, turns_count, forgetting_factor);
    // std::cout<<save_dir<<std::endl;

    for (int i=0; i<4; i++) {
        double curr_prob = knight_probabilities[i];
        std::string data_name = "p = " + std::to_string(curr_prob);

        std::string filename = get_sot_simulation_file_name(knight_probabilities[i], file_ext);
        std::filesystem::path file_path = join_path_with_filename(save_dir, filename);
        std::cout<<file_path<<std::endl;

        initialize(board_edge_len, curr_prob);
        move_all_knights_n_out_sigmas(
            turns_count,
            forget_after_N_turns,
            forgetting_factor,
            file_path,
            data_name,
            omit_sigma_turns);
        full_reset();
    }
}
