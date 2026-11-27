#pragma once

#include <fstream>
#include <filesystem>


// simulator_simulations.cpp
std::filesystem::path get_dirpath_output_esot(std::filesystem::path project_path);
std::string get_esot_simulation_dir_name(
    int board_edge_len,
    int turns_count,
    float forgetting_factor);
std::filesystem::path create_and_get_esot_simulation_dir(
    std::filesystem::path project_path,
    int board_edge_len,
    int turns_count,
    float forgetting_factor
);
std::string get_sot_simulation_file_name(double knight_probability, std::string file_ext);

// Common
std::string add_file_ext(std::string filename, std::string extension);
std::filesystem::path get_project_path(char *argv[]);
void rename_with_datetime(std::filesystem::path &filepath);
std::filesystem::path join_path_with_filename(
    std::filesystem::path sot_outputs_dir,
    std::string filename);
