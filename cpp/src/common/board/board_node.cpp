#include <iostream>

#include "board_node.h"


BoardNode::BoardNode() {
    is_knight = false;
    wins = 0;
    index_on_board = -1;
    i_in_indexes = -1;
}

BoardNode::BoardNode(bool in_is_knight, int in_index_on_board) {
    is_knight = in_is_knight;
    wins = 0;
    i_in_indexes = -1;
    index_on_board = in_index_on_board;
}

BoardNode::BoardNode(bool in_is_knight, int in_i_in_indexes, int in_index_on_board) {
    is_knight = in_is_knight;
    wins = 0;
    i_in_indexes = in_i_in_indexes;
    index_on_board = in_index_on_board;
}



void BoardNode::add_fight_win() {
    wins++;
}

void BoardNode::forget(float forgetting_factor) {
    wins = std::round(wins*(1-forgetting_factor));
}

std::string BoardNode::get_wins_to_print(std::string empty_char) {
    if (get_is_knight()) {
        std::string stringed_num = std::to_string(get_wins());

        if      (stringed_num.length() == 1) return " " + stringed_num + " ";
        else if (stringed_num.length() == 2) return " " + stringed_num;
        else                                 return stringed_num;
    }
    else return " " + empty_char + " ";
}


bool BoardNode::get_is_knight() {
    return is_knight;
}

void BoardNode::set_is_knight(bool in_is_knight) {
    is_knight = in_is_knight;
}

int BoardNode::get_i_in_indexes() {
    return i_in_indexes;
}

void BoardNode::set_i_in_indexes(int in_i) {
    i_in_indexes = in_i;
}

int BoardNode::get_index_on_board() {
    return index_on_board;
}

void BoardNode::set_index_on_board(int new_index) {
    index_on_board = new_index;
}

int BoardNode::get_wins() {
    return wins;
}
