#include <iostream>
#include <fstream>
#include <filesystem>

#include "utils.h"
#include "board_node.h"


std::string get_num_to_print(BoardNode* node_adress, std::string empty_char) {
    if (node_adress->get_is_knight()) {
        std::string stringed_num = std::to_string(node_adress->get_wins());

        if      (stringed_num.length() == 1) return " " + stringed_num + " ";
        else if (stringed_num.length() == 2) return " " + stringed_num;
        else                                 return stringed_num;
    }
    else return " " + empty_char + " ";
}

std::filesystem::path get_filepath_in_out_sigma_over_time(
        std::filesystem::path project_path,
        std::string filename) {
    namespace fs = std::filesystem;
    fs::path out_file_path(project_path);
    filename = filename + ".txt";
    out_file_path = out_file_path / "output" / "sigma_over_time" / filename;
    return out_file_path;
}
