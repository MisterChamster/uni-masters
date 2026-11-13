#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <algorithm>

#include "board.h"


Board::Board() {
    edge_len = 0;
    total_nodes = 0;
    total_knights = 0;
}

Board::Board(int in_edge_len) {
    edge_len = in_edge_len;
    total_nodes = in_edge_len*in_edge_len;
    total_knights = 0;
    Board::create_empty_board_fields();
}

Board::Board(int in_edge_len, float appear_prob) {
    edge_len = in_edge_len;
    total_nodes = in_edge_len*in_edge_len;
    create_empty_board_fields();
    fill_board_knights(appear_prob);
}


void Board::create_empty_board_fields() {
    board_fields.resize(total_nodes);
    for(int i=0; i<total_nodes; i++) {
        board_fields[i] = new BoardNode(false, i);
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
    knight_nodes_adresses.resize(numof_knights);
    total_knights = numof_knights;

    for (int i=total_nodes-1; i>=numof_knights; i--) {
        knight_indexes.erase(knight_indexes.begin() + i);
    }
    sort(knight_indexes.begin(), knight_indexes.end());

    for (int i=0; i<knight_indexes.size(); i++) {
        int knight_index = knight_indexes[i];
        board_fields[knight_index]->set_is_knight(true);
        board_fields[knight_index]->set_i_in_indexes(i);
        knight_nodes_adresses[i] = board_fields[knight_index];
    }
}


int* Board::get_neighbors(int index) {
    static int neighbors[neighbors_count];

    neighbors[0] = (index - edge_len + total_nodes)%total_nodes;
    neighbors[1] = (index - edge_len + total_nodes)%total_nodes + 1 - ((index+1)%edge_len == 0)*edge_len;
    neighbors[2] = index - 1 + ((index+edge_len)%edge_len == 0)*edge_len;
    neighbors[3] = index + 1 - ((index+1)%edge_len == 0)*edge_len;
    neighbors[4] = (index + edge_len)%total_nodes - 1 + ((index+edge_len)%edge_len == 0)*edge_len;
    neighbors[5] = (index + edge_len)%total_nodes;
    return neighbors;
}

int Board::get_random_neighbor(int index) {
    int* neighbors = get_neighbors(index);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 5);
    int neighbor_index = dist6(rng);
    return neighbors[neighbor_index];
}

int Board::get_total_knights() {
    return total_knights;
}

void Board::swap_knight_with_empty(int i_knight, int i_node) {
    board_fields[i_knight]->set_index_on_board(i_node);
    std::swap(board_fields[i_knight], board_fields[i_node]);
}

void Board::swap_knights(int i_knight1, int i_knight2) {
    board_fields[i_knight1]->set_index_on_board(i_knight2);
    board_fields[i_knight2]->set_index_on_board(i_knight1);
    std::swap(board_fields[i_knight1], board_fields[i_knight2]);
}
