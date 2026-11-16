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

std::filesystem::path get_filepath_in_out_sot(
        std::filesystem::path project_path,
        std::string filename) {
    namespace fs = std::filesystem;
    fs::path out_file_path(project_path);
    filename = filename + ".txt";
    out_file_path = out_file_path / "output" / "sigma_over_time" / filename;
    return out_file_path;
}

std::string get_formatted_datetime() {
    char buffer[20] = {};
    std::time_t now = std::time(nullptr);
    std::strftime(
        buffer,
        sizeof(buffer),
        "_%Y-%m-%d_%H-%M-%S",
        std::localtime(&now));
    return buffer;
}

void rename_with_datetime(std::filesystem::path &filepath) {
    filepath.replace_filename(
        filepath.stem().string() +
        get_formatted_datetime() +
        filepath.extension().string());
}

std::filesystem::path get_new_filepath_in_out_sot(
        std::filesystem::path project_path,
        std::string filename) {
    std::filesystem::path save_path = get_filepath_in_out_sot(project_path, filename);
    if (std::filesystem::exists(save_path)) rename_with_datetime(save_path);

    return save_path;
}
