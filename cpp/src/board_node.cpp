#include <iostream>

#include "board_node.h"


// Has to exist for vector allocator
BoardNode::BoardNode() {
    is_knight = false;
    wins = 0;
    total_fights = 0;
    index_on_board = -1;
    i_in_indexes = -1;
}

BoardNode::BoardNode(bool in_is_knight, int in_index_on_board) {
    is_knight = in_is_knight;
    wins = 0;
    total_fights = 0;
    i_in_indexes = -1;
    index_on_board = in_index_on_board;
}

BoardNode::BoardNode(bool in_is_knight, int in_i_in_indexes, int in_index_on_board) {
    is_knight = in_is_knight;
    wins = 0;
    total_fights = 0;
    i_in_indexes = in_i_in_indexes;
    index_on_board = in_index_on_board;
}

void BoardNode::set_is_knight(bool in_is_knight) {
    is_knight = in_is_knight;
}

bool BoardNode::get_is_knight() {
    return is_knight;
}

void BoardNode::set_i_in_indexes(int in_i) {
    i_in_indexes = in_i;
}

int BoardNode::get_i_in_indexes() {
    return i_in_indexes;
}

int BoardNode::get_index_on_board() {
    return index_on_board;
}

void BoardNode::set_index_on_board(int new_index) {
    index_on_board = new_index;
}

void BoardNode::add_fight_win() {
    wins++;
    total_fights++;
}

int BoardNode::get_wins() {
    return wins;
}

void BoardNode::forget(float forgetting_factor) {
    // std::cout<<"Old wins: "<<wins<<std::endl;
    // float factor = 1-forgetting_factor;
    // std::cout<<"Factorrr: "<<factor<<std::endl;
    wins = std::round(wins*(1-forgetting_factor));
    // std::cout<<"New wins: "<<wins<<std::endl;
}
