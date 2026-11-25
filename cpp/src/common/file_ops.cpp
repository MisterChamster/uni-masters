#include <fstream>
#include <filesystem>

#include <sstream>
#include <iomanip>
#include <string>

#include "file_ops.h"
#include "utils.h"
#include "config.hpp"


// simulator.cpp
std::filesystem::path get_dirpath_output_sot(std::filesystem::path project_path) {
    std::filesystem::path out_file_path = project_path / "output" / "sigma_over_time";
    return out_file_path;
}

std::filesystem::path get_filepath_in_out_sot(
        std::filesystem::path sot_outputs_dir,
        std::string filename) {
    filename = add_file_ext(filename, config::SOT_FILE_EXT);
    std::filesystem::path out_file_path = sot_outputs_dir / filename;
    return out_file_path;
}

std::filesystem::path get_new_filepath_in_out_sot(
        std::filesystem::path sot_outputs_dir,
        std::string filename) {
    std::filesystem::path save_path = get_filepath_in_out_sot(sot_outputs_dir, filename);
    if (std::filesystem::exists(save_path)) rename_with_datetime(save_path);

    return save_path;
}

// simulator_simulations.cpp
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

std::string get_sot_simulation_file_name(double knight_probability) {
    std::string filename_base = config::SOT_FILENAME_BASE;

    std::ostringstream oss;
    oss << filename_base << "p=" << std::fixed << std::setprecision(3) << knight_probability;
    std::string filename_add = oss.str();

    std::string filename = filename_base + filename_add;
    return filename;
}

std::filesystem::path create_and_get_sot_simulation_folder(
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
