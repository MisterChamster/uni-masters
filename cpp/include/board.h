#pragma once

#include "board_node.h"
#include "knight.h"


class Board {
private:
    int edge_len;
    int total_nodes;
    int total_knights;
    static constexpr int neighbors_len = 6;
    std::vector<BoardNode> board_fields;
    std::vector<BoardNode*> knight_nodes_ptrs;

    void EXAMPLEfill_board_fields();
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

    int get_knightnode_index(BoardNode* node_ptr);
    int* get_neighbors(int index);
};
