#pragma once

#include <fstream>
#include <filesystem>


// simulator.cpp
std::filesystem::path get_dirpath_output_sot(std::filesystem::path project_path);
std::filesystem::path get_filepath_in_out_sot(
    std::filesystem::path sot_outputs_dir,
    std::string filename);
std::filesystem::path get_new_filepath_in_out_sot(
    std::filesystem::path sot_outputs_dir,
    std::string filename);

// simulator_simulations.cpp
// void create_sot_simulation_folder(std::filesystem::path project_path);
std::filesystem::path create_and_get_sot_simulation_folder(std::filesystem::path project_path);

// Common
std::string add_file_ext(std::string filename, std::string extension);
std::filesystem::path get_project_path(char *argv[]);
void rename_with_datetime(std::filesystem::path &filepath);
