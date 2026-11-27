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
    std::string file_ext = config::ESOT_FILE_EXT;
    std::filesystem::path save_dir = create_and_get_sot_simulation_dir(
        project_path, board_edge_len, turns_count, forgetting_factor, true);

    for (double curr_p : config::TEST_P_VALS) {
        std::string data_name = "p = " + std::to_string(curr_p);

        std::string filename = get_sot_simulation_file_name(curr_p, file_ext);
        std::filesystem::path file_path = join_path_with_filename(save_dir, filename);
        std::cout<<file_path<<std::endl;

        initialize(board_edge_len, curr_p);
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


void simulate_sigma_over_time(
        int board_edge_len,
        int turns_count,
        const std::vector<double>& values,
        int forget_after_N_turns,
        float forgetting_factor,
        std::filesystem::path save_path,
        int omit_sigma_turns=config::DEFAULT_TURNS_OMIT_SIGMA) {

    std::string file_ext = config::SOT_FILE_EXT;
}
