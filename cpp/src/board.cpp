#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <algorithm>

#include "board.h"


Board::Board(int in_edge_len) {
    edge_len = in_edge_len;
    total_nodes = in_edge_len*in_edge_len;
    total_knights = 0;
    sigma = 1;
    sigma_calc = SigmaCalculator();
    Board::create_empty_board_fields();
}

Board::Board(int in_edge_len, float appear_prob) {
    edge_len = in_edge_len;
    total_nodes = in_edge_len*in_edge_len;
    sigma = 1;
    sigma_calc = SigmaCalculator();
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

void Board::swap_knight_with_empty(int i_knight, int i_node) {
    board_fields[i_knight]->set_index_on_board(i_node);
    std::swap(board_fields[i_knight], board_fields[i_node]);
}

void Board::swap_knights(int i_knight1, int i_knight2) {
    board_fields[i_knight1]->set_index_on_board(i_knight2);
    board_fields[i_knight2]->set_index_on_board(i_knight1);
    std::swap(board_fields[i_knight1], board_fields[i_knight2]);
}

double Board::calc_winning_prob(int wins_k1, int wins_k2, float control_param) {
    return 1/(1+exp(control_param*(wins_k2-wins_k1)));
}

void Board::move_all_knights(bool forget_now, float forgetting_factor, bool use_sigma) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    double control_param = use_sigma ? sigma : 1;

    for (int i=0; i<total_knights; i++) {
        BoardNode* knight_address = knight_nodes_adresses[i];
        int knight_index = knight_address->get_index_on_board();
        int target_index = get_random_neighbor(knight_index);
        BoardNode* target_address = board_fields[target_index];

        if (target_address->get_is_knight()) {
            double knight_winning_prob = calc_winning_prob(
                knight_address->get_wins(),
                target_address->get_wins(),
                control_param);
            sigma_calc.add_winning_prob(knight_winning_prob);
            double rand_num_doble = dist(gen);

            bool fight_won_flag = (rand_num_doble<=knight_winning_prob);
            if (fight_won_flag) {
                knight_address->add_fight_win();
                swap_knights(knight_index, target_index);
            }
        } else {
            swap_knight_with_empty(knight_index, target_index);
        }
    }

    if (forget_now) {
        for (int i=0; i<total_knights; i++) {
            knight_nodes_adresses[i]->forget(forgetting_factor);
        }
    }
}

void Board::update_sigma() {
    sigma = sigma_calc.get_sigma_and_reset();
}

void Board::move_all_knights_n(int n, int forget_after_N_steps, float forgetting_factor) {
    for (int i=0; i<n; i++) {
        std::cout<<i<< ". SIGMA: "<<sigma<<std::endl;
        bool perform_forgetting;
        if (!(i%forget_after_N_steps)) perform_forgetting = true;
        else perform_forgetting = false;

        move_all_knights(perform_forgetting, forgetting_factor, true);
        if (i>=9) update_sigma();
        else sigma_calc.reset_vals();
    }
}
