#include <fstream>
#include <filesystem>

#include <file_ops.h>
#include "utils.h"


std::filesystem::path get_filepath_in_out_sot(
        std::filesystem::path project_path,
        std::string filename) {
    std::filesystem::path out_file_path(project_path);
    filename = filename + ".txt";
    out_file_path = out_file_path / "output" / "sigma_over_time" / filename;
    return out_file_path;
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
