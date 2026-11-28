#include <fstream>
#include <filesystem>

#include "file_ops.h"
#include "utils.h"


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
