#pragma once

#include <fstream>
#include <filesystem>


// simulator.cpp
void rename_with_datetime(std::filesystem::path &filepath);
std::filesystem::path get_filepath_in_out_sot(
    std::filesystem::path project_path,
    std::string filename);
std::filesystem::path get_new_filepath_in_out_sot(
    std::filesystem::path project_path,
    std::string filename);