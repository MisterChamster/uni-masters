#include <iostream>

#include "board.h"


Board::Board(int in_edge_len) {
    edge_len = in_edge_len;
    board_fields.resize(edge_len);
    Board::EXAMPLEfill_board_fields();
}


void Board::EXAMPLEfill_board_fields() {
    for(int i=0; i<edge_len; i++) {
        board_fields[i] = BoardNode();
    }
}
