#include <iostream>
#include <random>
#include <fstream>
#include <iostream>

#include "simulator.h"
#include "board.h"


Simulator::Simulator(int board_edge_len, double knight_probability) {
    sigma = 0;
    sigma_calc = SigmaCalculator();
    board = Board(board_edge_len, knight_probability);
}

Board* Simulator::get_board_ptr() {
    return &board;
}

void Simulator::update_sigma() {
    sigma = sigma_calc.get_sigma_and_reset();
}

double Simulator::calc_winning_prob(int wins_k1, int wins_k2, float control_param) {
    return 1/(1+exp(control_param*(wins_k2-wins_k1)));
}

void Simulator::move_all_knights(bool forget_now, float forgetting_factor, bool use_sigma) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    int total_knights = board.get_total_knights();
    double control_param = use_sigma ? sigma : 1;

    for (int i=0; i<total_knights; i++) {
        BoardNode* knight_address = board.knight_nodes_adresses[i];
        int knight_index = knight_address->get_index_on_board();
        int target_index = board.get_random_neighbor(knight_index);
        BoardNode* target_address = board.board_fields[target_index];

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
                board.swap_knights(knight_index, target_index);
            }
        } else {
            board.swap_knight_with_empty(knight_index, target_index);
        }
    }

    if (forget_now) {
        for (int i=0; i<total_knights; i++) {
            board.knight_nodes_adresses[i]->forget(forgetting_factor);
        }
    }
}


void Simulator::move_all_knights_n(int moves_count, int forget_after_N_steps, float forgetting_factor) {
    int n_steps_omit_sigma = (moves_count <= 10) ? moves_count : 10;

    for (int i=0; i<n_steps_omit_sigma; i++) {
        sigma_calc.reset_vals();
        bool perform_forgetting = (!(i%forget_after_N_steps)) ? true : false;
        move_all_knights(perform_forgetting, forgetting_factor, false);
    }

    update_sigma();
    // Should I handle 0 sigma in second loop?
    for (int i=n_steps_omit_sigma; i<moves_count; i++) {
        std::cout<<i<< ". SIGMA: "<<sigma<<std::endl;
        bool perform_forgetting = (!(i%forget_after_N_steps)) ? true : false;
        move_all_knights(perform_forgetting, forgetting_factor, true);
        update_sigma();
    }
}

std::filesystem::path get_filepath_in_out_sigma_over_time(
        std::filesystem::path in_project_path,
        std::string filename) {
    namespace fs = std::filesystem;
    fs::path out_file_path(in_project_path);
    filename = filename + ".csv";
    out_file_path = out_file_path / "output" / "sigma_over_time" / filename;
    return out_file_path;
}

// Appends to end of file
void Simulator::move_all_knights_n_out_sigmas(
        int moves_count,
        int forget_after_N_steps,
        float forgetting_factor,
        std::filesystem::path in_project_path,
        std::string filename,
        std::string data_name) {

    std::filesystem::path out_file_path = get_filepath_in_out_sigma_over_time(in_project_path, filename);
    std::ofstream file(out_file_path, std::ios::app);
    file<<data_name<<"\n";

    int n_steps_omit_sigma = (moves_count <= 10) ? moves_count : 10;

    for (int i=0; i<n_steps_omit_sigma; i++) {
        file<<i<<"\t"<<sigma<<"\n";
        sigma_calc.reset_vals();
        bool perform_forgetting = (!(i%forget_after_N_steps)) ? true : false;
        move_all_knights(perform_forgetting, forgetting_factor, false);
    }

    update_sigma();
    // Should I handle 0 sigma in second loop?
    for (int i=n_steps_omit_sigma; i<moves_count; i++) {
        file<<i<<"\t"<<sigma<<"\n";
        std::cout<<i<< ". SIGMA: "<<sigma<<std::endl;
        bool perform_forgetting = (!(i%forget_after_N_steps)) ? true : false;
        move_all_knights(perform_forgetting, forgetting_factor, true);
        update_sigma();
    }
    file<<"\n";
}
