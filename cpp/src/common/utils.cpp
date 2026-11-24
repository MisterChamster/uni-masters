#include <iostream>

#include "utils.h"


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
