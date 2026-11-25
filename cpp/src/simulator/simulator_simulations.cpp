#include <iostream>

#include "simulator.h"
#include "file_ops.h"
#include "config.hpp"


void Simulator::simulate_sigma_over_time(
        int board_edge_len,
        int moves_count,
        int forget_after_N_turns,
        float forgetting_factor,
        std::filesystem::path project_path,
        int omit_sigma_turns) {
    double knight_probabilities[4] = {0.25, 0.5, 0.75, 1.0};

    std::string filename_base = config::SOT_FILENAME_BASE;
    std::cout<<filename_base<<std::endl;
    std::filesystem::path sot_outputs_dir = get_dirpath_output_sot(project_path);
    std::filesystem::path save_path = get_new_filepath_in_out_sot(sot_outputs_dir, filename_base);

    for (int i=0; i<4; i++) {
        double curr_prob = knight_probabilities[i];
        std::string data_name = "p = " + std::to_string(curr_prob);

        initialize(board_edge_len, curr_prob);
        move_all_knights_n_out_sigmas(
            moves_count,
            forget_after_N_turns,
            forgetting_factor,
            save_path,
            data_name,
            omit_sigma_turns);
        full_reset();
    }
}
