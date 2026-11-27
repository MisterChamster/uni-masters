#pragma once

#include <vector>

#include "board.h"
#include "sigma_calc.h"
#include "config.hpp"


class Simulator {
private:
    // Fields
    Board board;
    double sigma;
    SigmaCalculator sigma_calc;

    // simulator.cpp
    void move_all_knights(bool forget_now, float forgetting_factor, bool use_sigma);
    double calc_winning_prob(int wins_k1, int wins_k2, float control_param=config::DEFAULT_CONTROL_PARAM);
    void update_sigma();

public:
    // simulator_construct_reset.cpp
    Simulator();
    Simulator(int board_edge_len, double knight_probability);
    void initialize(int board_edge_len, double knight_probability);
    void full_reset();
    void reconstruct(int board_edge_len, double knight_probability);

    // simulator.cpp
    Board* get_board_ptr();

    void move_all_knights_n(
        int turns_count,
        int forget_after_N_turns,
        float forgetting_factor,
        int omit_sigma_turns=config::DEFAULT_TURNS_OMIT_SIGMA);
    void move_all_knights_n_out_sigmas(
        int turns_count,
        int forget_after_N_turns,
        float forgetting_factor,
        std::filesystem::path save_path,
        std::string data_name,
        int omit_sigma_turns=config::DEFAULT_TURNS_OMIT_SIGMA);
    void TESTmove_all_knights_n_out_sigmas_CALC_OMIT_SIGMA(
        int turns_count,
        int forget_after_N_turns,
        float forgetting_factor,
        std::filesystem::path save_path,
        std::string data_name,
        int omit_sigma_turns=config::DEFAULT_TURNS_OMIT_SIGMA);

    // simulator_simulations.cpp
    void simulate_example_sigma_over_time(
        int board_edge_len,
        int turns_count,
        int forget_after_N_turns,
        float forgetting_factor,
        std::filesystem::path save_path,
        int omit_sigma_turns=config::DEFAULT_TURNS_OMIT_SIGMA,
        bool calc_sigma_when_omitted=false);
    void simulate_sigma_over_time(
        int board_edge_len,
        int turns_count,
        const std::vector<double>& values,
        int forget_after_N_turns,
        float forgetting_factor,
        std::filesystem::path save_path,
        int omit_sigma_turns=config::DEFAULT_TURNS_OMIT_SIGMA);
};
