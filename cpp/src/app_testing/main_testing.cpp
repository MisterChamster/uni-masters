#include <iostream>
#include <filesystem>

#include "board.h"
#include "simulator.h"


int main(int argc, char* argv[]) {
    if (argc != 6) {
        std::cerr<<"Too many arguments\n";
        return 1;}

    std::filesystem::path executable_path(argv[0]);
    std::filesystem::path project_path = executable_path.parent_path().parent_path().parent_path();

    std::cout<<"Hello arg!!: "<<argv[0]<<std::endl;
    std::cout<<"Hello arg!!: "<<argv[1]<<std::endl;
    std::cout<<"Hello arg!!: "<<argv[2]<<std::endl;
    std::cout<<"Hello arg!!: "<<argv[3]<<std::endl;
    std::cout<<"Hello arg!!: "<<argv[4]<<std::endl;
    std::cout<<"Hello arg!!: "<<argv[5]<<std::endl;

    int board_edge_len       = std::stoi(argv[1]);
    float knight_probability = std::stof(argv[2]);
    int moves_to_perform     = std::stoi(argv[3]);
    float forgetting_factor  = std::stof(argv[4]);
    int forget_after_N_steps = std::stoi(argv[5]);


    Simulator simulator = Simulator(
        board_edge_len,
        knight_probability);
    Board* board_ptr = simulator.get_board_ptr();
    // board_ptr->print_board_sqared();
    // std::cout<<std::endl;
// board_ptr->print_board_trianglar();
    board_ptr->print_board_trianglar_wins();
    // board_ptr->print_board_trianglar_wins();
    // std::cout<<std::endl;
    // board_ptr->print_board_trianglar_wins();
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;

    // simulator.move_all_knights_n(moves_to_perform, forget_after_N_steps, forgetting_factor);
    simulator.move_all_knights_n_out_sigmas(moves_to_perform, forget_after_N_steps, forgetting_factor, project_path, "testpath", "Data1");

    // board_ptr->print_board_trianglar_wins(".");
    std::cout<<std::endl;
    std::cout<<"HDKNFDABSNKCNAKN"<<std::endl;
    return 0;
}
