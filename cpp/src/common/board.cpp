#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <algorithm>

#include "board.h"


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
