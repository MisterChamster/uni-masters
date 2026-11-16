#pragma once

#include <fstream>
#include <filesystem>

#include "board_node.h"


// board_printers.cpp
std::string get_num_to_print(BoardNode* node_adress, std::string empty_char = " ");

// simulator.cpp
std::filesystem::path get_filepath_in_out_sigma_over_time(
    std::filesystem::path project_path,
    std::string filename);
