#pragma once

#include "board.h"
#include "sigma_calc.h"


class Simulator {
private:
    // Fields
    Board board;
    double sigma;
    SigmaCalculator sigma_calc;

    void move_all_knights(bool forget_now, float forgetting_factor, bool use_sigma);
    double calc_winning_prob(int wins_k1, int wins_k2, float control_param=1);
    void update_sigma();

public:
    Simulator(int board_edge_len, double knight_probability);

    Board* get_board_ptr();

    void move_all_knights_n(int moves_count, int forget_after_N_steps, float forgetting_factor);
    void move_all_knights_n_out_sigmas(int moves_count, int forget_after_N_steps, float forgetting_factor, std::filesystem::path in_project_path, std::string filename, std::string data_name);
};
