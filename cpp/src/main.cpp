#include <iostream>
#include <filesystem>

#include "board.h"


// Make globals file!
int main(int argc, char* argv[]) {
    std::filesystem::path project_path(argv[0]);
    project_path = project_path.parent_path().parent_path();

    if (argc != 6) {
        std::cerr<<"AYYYY LMAO CRINGE\n";
        return 1;
    }
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

    // int board_edge_len = 35;
    // float knight_probability = 0.75;
    // int moves_to_perform = 1;
    // float forgetting_factor = 0.1;
    // int forget_after_N_steps = 4;

    Board main_board = Board(
        board_edge_len,
        knight_probability);
    // main_board.print_board_sqared();
    // std::cout<<std::endl;
// main_board.print_board_trianglar();
    main_board.print_board_trianglar_wins();
    // std::cout<<std::endl;
    // main_board.print_board_trianglar_wins();
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;

    main_board.move_all_knights_n(moves_to_perform, forget_after_N_steps, forgetting_factor, project_path);

    // main_board.print_board_trianglar_wins(".");
    std::cout<<std::endl;
    std::cout<<"HDKNFDABSNKCNAKN"<<std::endl;
    return 0;
}
