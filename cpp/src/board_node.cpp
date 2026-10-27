#include <iostream>

#include "board_node.h"


BoardNode::BoardNode(bool in_is_knight) {
    is_knight = in_is_knight;
    node_knight = Knight();
}

void BoardNode::set_is_knight(bool in_is_knight) {
    is_knight = in_is_knight;
}

bool BoardNode::get_is_knight() {
    return is_knight;
}
