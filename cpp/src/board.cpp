#include <iostream>

#include "board.h"


Board::Board(int in_edge_len) {
    edge_len = in_edge_len;
    total_nodes = in_edge_len*in_edge_len;
    board_fields.resize(edge_len*edge_len);
    Board::EXAMPLEfill_board_fields();
}


void Board::EXAMPLEfill_board_fields() {
    for(int i=0; i<total_nodes; i++) {
        board_fields[i] = BoardNode();
    }

    // EXAMPLE FILL!!!
    board_fields[0].set_is_knight(true);
    board_fields[0].set_team(Team::team_1);
    board_fields[8].set_is_knight(true);
    board_fields[8].set_team(Team::team_1);
    board_fields[10].set_is_knight(true);
    board_fields[10].set_team(Team::team_1);
    board_fields[13].set_is_knight(true);
    board_fields[13].set_team(Team::team_1);
    board_fields[16].set_is_knight(true);
    board_fields[16].set_team(Team::team_1);
    board_fields[24].set_is_knight(true);
    board_fields[24].set_team(Team::team_1);

    board_fields[4].set_is_knight(true);
    board_fields[4].set_team(Team::team_2);
    board_fields[6].set_is_knight(true);
    board_fields[6].set_team(Team::team_2);
    board_fields[11].set_is_knight(true);
    board_fields[11].set_team(Team::team_2);
    board_fields[12].set_is_knight(true);
    board_fields[12].set_team(Team::team_2);
    board_fields[18].set_is_knight(true);
    board_fields[18].set_team(Team::team_2);
    board_fields[20].set_is_knight(true);
    board_fields[20].set_team(Team::team_2);
}

void Board::print_board() {
    for (int i=0; i<total_nodes; i++) {
        int node_val = 0;
        if (board_fields[i].get_is_knight()) node_val++;
        if (board_fields[i].get_team() == Team::team_2) node_val++;

        std::cout<<node_val<<" ";
        if ((i+1)%edge_len == 0) std::cout<<std::endl;
    }
}
