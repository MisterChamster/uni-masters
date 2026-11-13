#pragma once

#include <filesystem>
#include "board_node.h"
#include "sigma_calc.h"


class Board {
private:
    // Fields
    int edge_len;
    int total_nodes;
    int total_knights;
    static constexpr int neighbors_count = 6;

    double sigma;
    SigmaCalculator sigma_calc;
    std::vector<BoardNode*> board_fields;
    std::vector<BoardNode*> knight_nodes_adresses;

    // board.cpp
    Board(int len); //might be useless

    void create_empty_board_fields();
    void fill_board_knights(float appear_prob);

    double calc_winning_prob(int wins_k1, int wins_k2, float control_param=1);
    void update_sigma();
    int* get_neighbors(int index);
    int get_random_neighbor(int index);
    void swap_knight_with_empty(int i_knight, int i_node);
    void swap_knights(int i_knight1, int i_knight2);
    void move_all_knights(bool forget_now=false, float forgetting_factor=0.1, bool use_sigma=true);

public:
    // board.cpp
    Board(int len, float appear_prob);

    // board_printers.cpp
    void print_board_sqared();
    void print_board_trianglar();
    void print_board_trianglar_netted(); //don't use this function. it's ugly
    void print_board_trianglar_wins(std::string empty_char = " ");
    void print_neighbors(int n);
    void print_knight_nodes();

    // board_simulations.cpp
    void move_all_knights_n(int n, int forget_after_N_steps, float forgetting_factor);
    void move_all_knights_n(int n, int forget_after_N_steps, float forgetting_factor, std::filesystem::path exec_path);
};
