#pragma once

#include "knight.h"

class BoardNode {
private:
    bool is_knight;
    Knight node_knight;

public:
    BoardNode(bool in_is_knight);

    void set_is_knight(bool in_is_knight);
    bool get_is_knight();
};
