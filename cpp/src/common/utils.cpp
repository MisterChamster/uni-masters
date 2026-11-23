#include <iostream>

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
