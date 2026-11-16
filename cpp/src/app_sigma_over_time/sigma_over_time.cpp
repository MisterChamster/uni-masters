#include <iostream>
#include <filesystem>
#include <string>

#include "simulator.h"
#include "utils.h"


int main(int argc, char* argv[]) {
    if (argc > 2) {
        std::cerr<<"Too many arguments\n";
        return 1;}

    std::filesystem::path executable_path(argv[0]);
    std::filesystem::path project_path = executable_path.parent_path().parent_path();

    std::string filename = (argc==2) ? argv[1] : "sigma_over_time";
    std::cout<<filename<<std::endl;

    int board_edge_len = 100;
    int moves_to_perform = 500;
    int forget_after_N_steps = 4;
    float forgetting_factor = 0.1;
    Simulator simulator = Simulator();

    double knight_probabilities[4] = {0.25, 0.5, 0.75, 1.0};

    std::filesystem::path save_path = get_new_filepath_in_out_sot(project_path, filename);

    for (int i=0; i<4; i++) {
        double curr_prob = knight_probabilities[i];
        std::string data_name = "p = " + std::to_string(curr_prob);

        simulator.initialize(board_edge_len, curr_prob);
        simulator.move_all_knights_n_out_sigmas(
            moves_to_perform,
            forget_after_N_steps,
            forgetting_factor,
            project_path,
            save_path,
            data_name);
        simulator.full_reset();
    }

    return 0;
}
