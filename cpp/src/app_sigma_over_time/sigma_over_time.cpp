#include <iostream>
#include <filesystem>

#include "simulator.h"
#include "file_ops.h"


int main(int argc, char* argv[]) {
    int board_edge_len = 100;
    int turns_count = 500;
    int forget_after_N_turns = 4;
    float forgetting_factor = 0.1;
    int omit_sigma_turns = 10;
    std::filesystem::path project_path = get_project_path(argv);

    Simulator simulator = Simulator();
    simulator.simulate_sigma_over_time(
        board_edge_len,
        turns_count,
        forget_after_N_turns,
        forgetting_factor,
        project_path,
        omit_sigma_turns);

    return 0;
}
