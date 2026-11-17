#include <iostream>
#include <filesystem>
#include <string>

#include "simulator.h"
#include "utils.h"


int main(int argc, char* argv[]) {
    if (argc > 2) {
        std::cerr<<"Too many arguments\n";
        return 1;}

    int board_edge_len = 100;
    int moves_to_perform = 500;
    int forget_after_N_steps = 4;
    float forgetting_factor = 0.1;

    std::filesystem::path executable_path(argv[0]);
    std::filesystem::path project_path = executable_path.parent_path().parent_path();
    std::string filename = (argc==2) ? argv[1] : "sigma_over_time";
    std::cout<<filename<<std::endl;
    std::filesystem::path save_path = get_new_filepath_in_out_sot(project_path, filename);

    Simulator simulator = Simulator();
    simulator.simulate_sigma_over_time(
        board_edge_len,
        moves_to_perform,
        forget_after_N_steps,
        forgetting_factor,
        save_path);

    return 0;
}
