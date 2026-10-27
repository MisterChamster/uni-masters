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

void Board::print_neighbors(int index) {
    // print indexes
    // print teams
    std::vector<int> neighbors(edge_len);
    neighbors.resize(6);
    int temp;
    std::cout<<index<<": ";

    // top mid
    temp = (index - edge_len + total_nodes)%25;
    neighbors[0] = temp;
    // top right
    temp = (index - edge_len + total_nodes)%25 + 1 - ((index+1)%edge_len == 0)*edge_len;
    neighbors[1] = temp;
    // mid left
    temp = index - 1 + ((index+edge_len)%edge_len == 0)*edge_len;
    neighbors[2] = temp;
    // mid right
    temp = index + 1 - ((index+1)%edge_len == 0)*edge_len;
    neighbors[3] = temp;
    // down left
    temp = (index + edge_len)%25 - 1 + ((index+edge_len)%edge_len == 0)*edge_len;
    neighbors[4] = temp;
    // down mid
    temp = (index + edge_len)%25;
    neighbors[5] = temp;

    for (int i=0; i<6; i++) {
        std::cout<<neighbors[i]<<" ";
    }
    std::cout<<std::endl;
}
