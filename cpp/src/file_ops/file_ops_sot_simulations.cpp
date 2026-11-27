#include <fstream>
#include <filesystem>

#include <sstream>
#include <iomanip>
#include <string>

#include "file_ops.h"
#include "utils.h"
#include "config.hpp"


// simulator_simulations.cpp
std::filesystem::path get_dirpath_output_sot(
        std::filesystem::path project_path, bool is_example) {
    std::string dirname = is_example ? config::ESOT_OUTS_DIR : config::SOT_OUTS_DIR;
    std::filesystem::path out_dir_path = project_path / "output" / dirname;
    return out_dir_path;
}

std::string get_sot_simulation_dir_name(
        int board_edge_len,
        int turns_count,
        float forgetting_factor,
        bool is_example) {
    std::string dirname_base = is_example ? config::ESOT_DIRNAME_BASE : config::SOT_DIRNAME_BASE;

    std::ostringstream oss;
    oss << 
        "-" << "edge=" << std::to_string(board_edge_len) << "-" <<
        "turns=" << std::to_string(turns_count) << "-" <<
        "f=" << std::fixed << std::setprecision(3) << forgetting_factor << "-" <<
        "time=" << get_formatted_datetime();
    std::string dirname_add = oss.str();

    std::string dirname = dirname_base + dirname_add;
    return dirname;
}

std::filesystem::path create_and_get_sot_simulation_dir(
        std::filesystem::path project_path,
        int board_edge_len,
        int turns_count,
        float forgetting_factor,
        bool is_example) {
    std::filesystem::path outs_esot_dir = get_dirpath_output_sot(project_path, is_example);
    std::string dirname = get_sot_simulation_dir_name(board_edge_len, turns_count, forgetting_factor, is_example);
    std::filesystem::path new_dirpath = outs_esot_dir / dirname;

    std::filesystem::create_directory(new_dirpath);
    return new_dirpath;
}

std::string get_sot_simulation_file_name(double knight_probability, std::string file_ext) {
    std::ostringstream oss;
    oss << "p=" << std::fixed << std::setprecision(3) << knight_probability;
    std::string filename = oss.str();

    std::string filename_with_ext = add_file_ext(filename, file_ext);
    return filename_with_ext;
}
