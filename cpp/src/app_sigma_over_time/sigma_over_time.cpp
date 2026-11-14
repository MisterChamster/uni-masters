#include <iostream>
#include <filesystem>

#include "simulator.h"


int main(int argc, char* argv[]) {
    std::cout<<"Hello!\n";
    std::filesystem::path executable_path(argv[0]);
    std::filesystem::path project_path = executable_path.parent_path().parent_path().parent_path();

    int board_edge_len       = 30;
    float knight_probability = 0.75;

    Simulator simulator = Simulator(
        board_edge_len,
        knight_probability);

    return 0;
}
