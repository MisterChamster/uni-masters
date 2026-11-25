#include <fstream>
#include <filesystem>

#include <sstream>
#include <iomanip>
#include <string>

#include "file_ops.h"
#include "utils.h"
#include "config.hpp"


// simulator_simulations.cpp
std::string get_sot_simulation_file_name(double knight_probability, std::string file_ext) {
    // std::string filename_base = config::SOT_FILENAME_BASE;

    std::ostringstream oss;
    oss << "p=" << std::fixed << std::setprecision(3) << knight_probability;
    std::string filename = oss.str();

    // std::string filename = filename_base + filename_add;
    std::string filename_with_ext = add_file_ext(filename, file_ext);
    return filename_with_ext;
}

std::filesystem::path get_dirpath_output_sot(std::filesystem::path project_path) {
    std::filesystem::path out_file_path = project_path / "output" / "sigma_over_time";
    return out_file_path;
}

std::string get_sot_simulation_dir_name(
        int board_edge_len,
        int turns_count,
        float forgetting_factor) {
    std::string dirname_base = config::SOT_DIRNAME_BASE;

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
        float forgetting_factor) {
    std::filesystem::path outs_sot_dir = get_dirpath_output_sot(project_path);
    std::string dirname = get_sot_simulation_dir_name(board_edge_len, turns_count, forgetting_factor);
    std::filesystem::path new_dirpath = outs_sot_dir / dirname;

    std::filesystem::create_directory(new_dirpath);
    return new_dirpath;
}

// Common
std::string add_file_ext(std::string filename, std::string extension) {
    return filename + "." + extension;
}

std::filesystem::path get_project_path(char *argv[]) {
    std::filesystem::path executable_path(argv[0]);
    return executable_path.parent_path().parent_path();
}

void rename_with_datetime(std::filesystem::path &filepath) {
    filepath.replace_filename(
        filepath.stem().string() + "_" +
        get_formatted_datetime() +
        filepath.extension().string());
}

std::filesystem::path join_path_with_filename(
        std::filesystem::path sot_outputs_dir,
        std::string filename) {
    std::filesystem::path save_path = sot_outputs_dir / filename;

    return save_path;
}
