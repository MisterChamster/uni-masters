#pragma once

#include "knight.h"

class BoardNode {
private:
    bool is_knight;
    Knight node_knight;

public:
    BoardNode();
    BoardNode(Team in_team);

    void set_is_knight(bool in_is_knight);
    void set_team(Team in_team);
    bool get_is_knight();
    Team get_team();
};
