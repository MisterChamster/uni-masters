#include <iostream>

#include "simulator.h"
#include "file_ops.h"
#include "utils.h"
#include "config.hpp"


void Simulator::simulate_example_sigma_over_time(
        int board_edge_len,
        int turns_count,
        int forget_after_N_turns,
        float forgetting_factor,
        std::filesystem::path project_path,
        int omit_sigma_turns,
        bool calc_sigma_when_omitted) {
    double knight_probabilities[] = {0.1, 0.25, 0.5, 0.75, 1.0};
    int probs_arr_len = std::size(knight_probabilities);
    std::string file_ext = config::ESOT_FILE_EXT;
    std::filesystem::path save_dir = create_and_get_sot_simulation_dir(project_path, board_edge_len, turns_count, forgetting_factor);

    for (int i=0; i<probs_arr_len; i++) {
        double curr_prob = knight_probabilities[i];
        std::string data_name = "p = " + std::to_string(curr_prob);

        std::string filename = get_sot_simulation_file_name(knight_probabilities[i], file_ext);
        std::filesystem::path file_path = join_path_with_filename(save_dir, filename);
        std::cout<<file_path<<std::endl;

        initialize(board_edge_len, curr_prob);
        if (!calc_sigma_when_omitted) {
            move_all_knights_n_out_sigmas(
                turns_count,
                forget_after_N_turns,
                forgetting_factor,
                file_path,
                data_name,
                omit_sigma_turns);
        } else {
            TESTmove_all_knights_n_out_sigmas_CALC_OMIT_SIGMA(
                turns_count,
                forget_after_N_turns,
                forgetting_factor,
                file_path,
                data_name,
                omit_sigma_turns);
        }
        full_reset();
    }
}
