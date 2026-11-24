#pragma once

#include <fstream>
#include <filesystem>


class DataFile {
private:
    std::filesystem::path filepath;

    int get_nth_header(int header_n);

public:
    DataFile();
    DataFile(std::filesystem::path in_filepath);
    double* get_file_sigmas();

    void set_filepath();
    std::filesystem::path get_filepath();
};
