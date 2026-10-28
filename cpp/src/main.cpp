#include <iostream>

#include "board.h"


int main() {
    int board_edge_len = 20;
    float knight_probability = 0.99;

    Board main_board = Board(
        board_edge_len,
        knight_probability);
    // main_board.print_board_sqared();
    // std::cout<<std::endl;
    main_board.print_board_trianglar();
    // std::cout<<std::endl;
    // main_board.print_board_trianglar_netted();

    // main_board.print_neighbors(1);
    // main_board.print_neighbors(4);
    // main_board.print_neighbors(6);

    // main_board.print_neighbors(16);
    // main_board.print_neighbors(20);
    // main_board.print_neighbors(24);
    // std::cout<<"HEllo"<<std::endl;

    std::cout<<std::endl;
    main_board.print_knight_nodes();
    return 0;
}
