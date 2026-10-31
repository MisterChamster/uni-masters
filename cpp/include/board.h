#pragma once

#include "board_node.h"


class Board {
private:
    int edge_len;
    int total_nodes;
    int total_knights;
    static constexpr int neighbors_len = 6;
    std::vector<BoardNode> board_fields;
    std::vector<int> knight_nodes_indexes;

    void create_empty_board_fields();
    void fill_board_knights(float appear_prob);

public:
    Board(int len);
    Board(int len, float appear_prob);

    void print_board_sqared();
    void print_board_trianglar();
    void print_board_trianglar_netted();
    void print_neighbors(int n);
    void print_knight_nodes();

    int get_node_index(BoardNode* node_ptr);
    int* get_neighbors(int index);
    int get_random_neighbor(int index);
    void swap_nodes(int node_i1, int node_i2);
    void swap_knight_with_empty(int i_knight, int i_node, int knight_index_i);
    void swap_knights(int i_knight1, int i_knight2, int knight1_index_i);
    void move_all_knights();
    void move_all_knights_n(int n);
};
