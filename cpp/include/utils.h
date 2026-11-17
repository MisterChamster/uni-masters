#pragma once

#include <fstream>
#include <filesystem>

#include "board_node.h"


std::string get_formatted_datetime();
void rename_with_datetime(std::filesystem::path &filepath);

// board_printers.cpp
std::string get_num_to_print(BoardNode* node_adress, std::string empty_char = " ");

// simulator.cpp
std::filesystem::path get_filepath_in_out_sot(
    std::filesystem::path project_path,
    std::string filename);
std::filesystem::path get_new_filepath_in_out_sot(
    std::filesystem::path project_path,
    std::string filename);
