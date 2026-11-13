#include <iostream>
#include <filesystem>

#include "board.h"


void Board::move_all_knights_n(int moves_count, int forget_after_N_steps, float forgetting_factor) {
    int n_steps_omit_sigma = (moves_count <= 10) ? moves_count : 10;

    for (int i=0; i<n_steps_omit_sigma; i++) {
        sigma_calc.reset_vals();
        bool perform_forgetting = (!(i%forget_after_N_steps)) ? true : false;
        move_all_knights(perform_forgetting, forgetting_factor, false);
    }

    update_sigma();
    // Pls handle 0 sigma in second loop!
    for (int i=n_steps_omit_sigma; i<moves_count; i++) {
        std::cout<<i<< ". SIGMA: "<<sigma<<std::endl;
        bool perform_forgetting = (!(i%forget_after_N_steps)) ? true : false;
        move_all_knights(perform_forgetting, forgetting_factor, true);
        update_sigma();
    }
}


// Appends if exists, creates and writes if not
void Board::move_all_knights_n(int moves_count, int forget_after_N_steps, float forgetting_factor, std::filesystem::path exec_path) {
    namespace fs = std::filesystem;
    // fs::path sourceDir = fs::absolute(fs::path(__FILE__)).parent_path();
    std::filesystem::path out_sigma_path(exec_path);
    out_sigma_path = out_sigma_path.parent_path().parent_path();
    out_sigma_path = out_sigma_path / "output" / "sigma_over_time";

    if (fs::exists(out_sigma_path)) {
        std::cout << "File exists\n";
    } else {
        std::cout << "File does not exist\n";
    }
    // std::ofstream file(out_sigma_path, std::ios::app);
    std::cout << out_sigma_path << '\n';

    int n_steps_omit_sigma = (moves_count <= 10) ? moves_count : 10;

    for (int i=0; i<n_steps_omit_sigma; i++) {
        sigma_calc.reset_vals();
        bool perform_forgetting = (!(i%forget_after_N_steps)) ? true : false;
        move_all_knights(perform_forgetting, forgetting_factor, false);
    }

    update_sigma();
    // Pls handle 0 sigma in second loop!
    for (int i=n_steps_omit_sigma; i<moves_count; i++) {
        std::cout<<i<< ". SIGMA: "<<sigma<<std::endl;
        bool perform_forgetting = (!(i%forget_after_N_steps)) ? true : false;
        move_all_knights(perform_forgetting, forgetting_factor, true);
        update_sigma();
    }
}
