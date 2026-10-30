#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <algorithm>

#include "board.h"


Board::Board(int in_edge_len) {
    edge_len = in_edge_len;
    total_nodes = in_edge_len*in_edge_len;
    Board::create_empty_board_fields();
}

Board::Board(int in_edge_len, float appear_prob) {
    edge_len = in_edge_len;
    total_nodes = in_edge_len*in_edge_len;
    Board::create_empty_board_fields();
    Board::fill_board_knights(appear_prob);
}


void Board::create_empty_board_fields() {
    board_fields.resize(total_nodes);
    for(int i=0; i<total_nodes; i++) {
        board_fields[i] = BoardNode(false);
    }
}

void Board::fill_board_knights(float appear_prob) {
    if (appear_prob<0 || appear_prob>1) {
        throw std::invalid_argument("Argument is not a value between 0 and 1!!");
    }

    std::vector<int> knight_indexes(total_nodes);
    std::iota(knight_indexes.begin(), knight_indexes.end(), 0);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(knight_indexes.begin(), knight_indexes.end(), gen);

    int numof_knights = std::round(total_nodes*appear_prob);
    knight_nodes_indexes.resize(numof_knights);
    total_knights = numof_knights;

    for (int i=total_nodes-1; i>=numof_knights; i--) {
        knight_indexes.erase(knight_indexes.begin() + i);
    }
    sort(knight_indexes.begin(), knight_indexes.end());

    int k = 0;
    for (int i:knight_indexes) {
        board_fields[i].set_is_knight(true);
        knight_nodes_indexes[k] = i;
        k++;
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
    int* neighbors = get_neighbors(index);
    for (int i=0; i<neighbors_len; i++) {
        std::cout<<neighbors[i]<<" ";
    }
    std::cout<<std::endl;
}

void Board::print_knight_nodes() {
    std::cout<<"Index   Address\n";
    for (int curr_node_index:knight_nodes_indexes) {
        std::string node_str = std::to_string(curr_node_index);
        node_str.resize(5, ' ');
        std::cout<<node_str << "   " << &knight_nodes_indexes[curr_node_index]<<std::endl;
    }
}

int Board::get_knightnode_index(BoardNode* node_ptr) {
    int index = static_cast<int>(node_ptr - board_fields.data());
    return index;
}

int* Board::get_neighbors(int index) {
    static int neighbors[neighbors_len];

    neighbors[0] = (index - edge_len + total_nodes)%25;
    neighbors[1] = (index - edge_len + total_nodes)%25 + 1 - ((index+1)%edge_len == 0)*edge_len;
    neighbors[2] = index - 1 + ((index+edge_len)%edge_len == 0)*edge_len;
    neighbors[3] = index + 1 - ((index+1)%edge_len == 0)*edge_len;
    neighbors[4] = (index + edge_len)%25 - 1 + ((index+edge_len)%edge_len == 0)*edge_len;
    neighbors[5] = (index + edge_len)%25;
    return neighbors;
}

int Board::get_random_neighbor(int index) {
    int* neighbors = get_neighbors(index);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 5);
    return neighbors[dist6(rng)];
}

void Board::swap_nodes(int node_i1, int node_i2) {
    bool node1_is_knight = board_fields[node_i1].get_is_knight();
    bool node2_is_knight = board_fields[node_i2].get_is_knight();
    if (node1_is_knight) {

    }
    if (node2_is_knight) {

    }
    std::swap(board_fields[node_i1], board_fields[node_i2]);
    // THIS FUCKS UP POINTERS VECTOR - FIX IT
    // Change pointers to indexes(?)
    // Remember to swap indexes... :(((
}

void Board::move_all_knights() {

}
