#include <iostream>

#include "board_node.h"


BoardNode::BoardNode(bool in_is_knight) {
    is_knight = in_is_knight;
    node_knight = Knight();
}
