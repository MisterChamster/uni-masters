#include <iostream>

#include "board.h"


Board::Board(int in_edge_len) {
    edge_len = in_edge_len;
    total_nodes = in_edge_len*in_edge_len;
    Board::create_empty_board_fields();
    Board::EXAMPLEfill_board_fields();
}


void Board::create_empty_board_fields() {
    board_fields.resize(total_nodes);
    for(int i=0; i<total_nodes; i++) {
        board_fields[i] = BoardNode(false);
    }
}

void Board::EXAMPLEfill_board_fields() {
    // EXAMPLE FILL!!!
    board_fields[0].set_is_knight(true);
    board_fields[8].set_is_knight(true);
    board_fields[10].set_is_knight(true);
    board_fields[13].set_is_knight(true);
    board_fields[16].set_is_knight(true);
    board_fields[24].set_is_knight(true);

    board_fields[4].set_is_knight(true);
    board_fields[6].set_is_knight(true);
    board_fields[11].set_is_knight(true);
    board_fields[12].set_is_knight(true);
    board_fields[18].set_is_knight(true);
    board_fields[20].set_is_knight(true);
}

void Board::print_board_sqared() {
    for (int i=0; i<total_nodes; i+=edge_len) {
        if ((i+1)%edge_len == 0) std::cout<<std::endl;

        for (int j=i; j<i+edge_len; j++) {
            int node_val = 0;
            if (board_fields[j].get_is_knight()) node_val++;
            std::cout<<node_val<<" ";
        }
        std::cout<<std::endl;
    }
}

void Board::print_board_trianglar() {
    int node_val = 0;
    for (int i=0; i<total_nodes; i+=edge_len*2) {
        std::cout<<" ";
        int j=i;
        while (j<i+edge_len) {
            if (board_fields[j].get_is_knight()) node_val++;
            std::cout<<node_val<<" ";
            node_val = 0;
            j++;
        }
        std::cout<<std::endl;

        if (i+1<total_nodes-edge_len) {
            for (int k=j; k<j+edge_len; k++) {
                if (board_fields[k].get_is_knight()) node_val++;
                std::cout<<node_val<<" ";
                node_val = 0;
            }
            std::cout<<std::endl;
        }
    }
}

void Board::print_board_trianglar_netted() {
    int node_val = 0;
    // std::cout<<"  ";
    if (board_fields[0].get_is_knight()) node_val++;
    node_val = 0;


    for (int i=1; i<total_nodes; i+=edge_len*2) {
        std::cout<<"  ";
        int j=i;
        while (j<i+edge_len) {
            if (board_fields[j].get_is_knight()) node_val++;
            std::cout<<node_val<<"   ";
            node_val = 0;
            j++;
        }


        if (!(i==(total_nodes-edge_len+1))){
            std::string somestring = "  ʌ";
            for (int l=0; l<edge_len-2; l++) {
                somestring += "   ʌ";
            }
            somestring += "  /";
            std::cout<<std::endl<<somestring<<std::endl;
        }

        if (i+1<total_nodes-edge_len) {
            if (board_fields[j].get_is_knight()) node_val++;
            std::cout<<node_val;
            node_val = 0;

            for (int k=j+1; k<j+edge_len; k++) {
                if (board_fields[k].get_is_knight()) node_val++;
                std::cout<<" - "<<node_val;
                node_val = 0;
            }

            if (!(j==(total_nodes-edge_len+1))){
                std::string somestring = "  v";
                for (int l=0; l<edge_len-2; l++) {
                    somestring += "   v";
                }
                somestring += "  \\";
                std::cout<<std::endl<<somestring;
            }
            std::cout<<std::endl;
        }
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
