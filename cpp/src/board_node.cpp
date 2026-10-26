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

void BoardNode::set_is_knight(bool in_is_knight) {
    is_knight = in_is_knight;
}

void BoardNode::set_team(Team in_team) {
    node_knight.set_team(in_team);
}

bool BoardNode::get_is_knight() {
    return is_knight;
}

Team BoardNode::get_team() {
    return node_knight.get_team();
}
