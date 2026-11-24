#include <iostream>
#include <filesystem>

#include "simulator.h"
#include "file_ops.h"


int main(int argc, char* argv[]) {
    int board_edge_len = 100;
    int moves_to_perform = 500;
    int forget_after_N_turns = 4;
    float forgetting_factor = 0.1;
    std::filesystem::path project_path = get_project_path(argv);

    Simulator simulator = Simulator();
    simulator.simulate_sigma_over_time(
        board_edge_len,
        moves_to_perform,
        forget_after_N_turns,
        forgetting_factor,
        project_path);

    return 0;
}
