#include <iostream>

#include "board_node.h"


// Has to exist for vector allocator
BoardNode::BoardNode() {
    is_knight = false;
    wins = 0;
    total_fights = 0;
}

BoardNode::BoardNode(bool in_is_knight) {
    is_knight = in_is_knight;
    wins = 0;
    total_fights = 0;
}

void BoardNode::set_is_knight(bool in_is_knight) {
    is_knight = in_is_knight;
}

bool BoardNode::get_is_knight() {
    return is_knight;
}
