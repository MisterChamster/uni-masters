#include <iostream>
#include <filesystem>

#include "simulator.h"


int main(int argc, char* argv[]) {
    if (argc > 2) {
        std::cerr<<"Too many arguments\n";
        return 1;}

    std::filesystem::path executable_path(argv[0]);
    std::filesystem::path project_path = executable_path.parent_path().parent_path().parent_path();

    std::string filename = (argc==2) ? argv[1] : "sigma_over_time";
    std::cout<<filename<<std::endl;

    int board_edge_len = 100;
    int moves_to_perform = 300;
    int forget_after_N_steps = 4;
    float forgetting_factor = 0.1;
    Simulator simulator = Simulator(
        board_edge_len,
        0.25);

    simulator.move_all_knights_n_out_sigmas(
        moves_to_perform,
        forget_after_N_steps,
        forgetting_factor,
        project_path,
        filename,
        "p = 0.25"
    );

    std::cout<<"Hello!\n";
    return 0;
}
