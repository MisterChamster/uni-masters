#pragma once

#include "board_node.h"


std::string get_formatted_datetime();

// board_printers.cpp
std::string get_num_to_print(BoardNode* node_adress, std::string empty_char = " ");
