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

    int board_edge_len       = 30;
    float knight_probability = 0.75;

    Simulator simulator = Simulator(
        board_edge_len,
        knight_probability);

    std::cout<<"Hello!\n";
    return 0;
}
