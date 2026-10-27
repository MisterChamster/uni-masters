#include <iostream>

#include "board_node.h"


// Has to exist for vector allocator
BoardNode::BoardNode() {
    is_knight = false;
    node_knight = Knight();
}

BoardNode::BoardNode(bool is_in_knight) {
    is_knight = is_in_knight;
    node_knight = Knight();
}

void BoardNode::set_is_knight(bool in_is_knight) {
    is_knight = in_is_knight;
}

bool BoardNode::get_is_knight() {
    return is_knight;
}
