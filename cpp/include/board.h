#pragma once

#include <filesystem>

#include "board_node.h"


class Board {
private:
    // Fields
    int edge_len;
    int total_nodes;
    int total_knights;
    static constexpr int neighbors_count = 6;

    // board_construct_reset.cpp
    void create_empty_board_fields(int in_total_nodes);
    void fill_board_knights(float appear_prob);
    void reset_vector_fields();
    void reset_non_vectors();
    void reset_board();

    // board.cpp
    int* get_neighbors(int index);

public:
    // Fields
    std::vector<BoardNode*> board_fields;
    std::vector<BoardNode*> knight_nodes_adresses;

    // board_construct_reset.cpp
    Board();
    Board(int len, float appear_prob);

    // board.cpp
    int get_random_neighbor(int index);
    int get_total_knights();
    void swap_knight_with_empty(int i_knight, int i_node);
    void swap_knights(int i_knight1, int i_knight2);

    // board_printers.cpp
    void print_board_sqared();
    void print_board_trianglar();
    void print_board_trianglar_netted(); //don't use this function. it's ugly
    void print_board_trianglar_wins(std::string empty_char = " ");
    void print_neighbors(int n);
    void print_knight_nodes();
};
