#include <iostream>

#include "board_node.h"


// Constructor for empty node
BoardNode::BoardNode() {
    is_knight = false;
    node_knight = Knight();
}

// Constructor for empty node
BoardNode::BoardNode(Team in_team) {
    is_knight = true;
    node_knight = Knight(in_team);
}
