#include <iostream>

#include "board.h"


int main() {
    int board_edge_len = 5;
    float knight_probability = 0.5;
    int moves_to_perform = 20;
    float forgetting_factor = 0.1;
    int forget_after_N_steps = 4;

    Board main_board = Board(
        board_edge_len,
        knight_probability);
    // main_board.print_board_sqared();
    // std::cout<<std::endl;
    main_board.print_board_trianglar();
    std::cout<<std::endl;
    // main_board.print_board_trianglar_netted();
    // std::cout<<std::endl;
    // main_board.print_board_trianglar_wins();
    // std::cout<<std::endl;

    // main_board.print_neighbors(1);
    // main_board.print_neighbors(4);
    // main_board.print_neighbors(6);

    // main_board.print_neighbors(16);
    // main_board.print_neighbors(20);
    // main_board.print_neighbors(24);
    // std::cout<<"HEllo"<<std::endl;

    // main_board.print_knight_nodes();
// std::cout<<std::endl;

    main_board.move_all_knights_n(moves_to_perform, forget_after_N_steps, forgetting_factor);
    main_board.print_board_trianglar();
    std::cout<<"HDKNFDABSNKCNAKN"<<std::endl;
    return 0;
}
