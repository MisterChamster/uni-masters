#include <fstream>
#include <filesystem>

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

std::string add_file_ext(std::string filename, std::string extension) {
    return filename + "." + extension;
}

std::filesystem::path get_project_path(char *argv[]) {
    std::filesystem::path executable_path(argv[0]);
    return executable_path.parent_path().parent_path();
}

void rename_with_datetime(std::filesystem::path &filepath) {
    filepath.replace_filename(
        filepath.stem().string() +
        get_formatted_datetime() +
        filepath.extension().string());
}
