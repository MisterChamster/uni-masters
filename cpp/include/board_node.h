#pragma once


class BoardNode {
private:
    bool is_knight;
    int wins;
    int index_on_board;
    int i_in_indexes;

public:
    BoardNode();
    BoardNode(bool in_is_knight, int in_index_on_board);
    BoardNode(bool in_is_knight, int in_i_in_indexes, int in_index_on_board);

    void set_is_knight(bool in_is_knight);
    bool get_is_knight();
    void set_i_in_indexes(int in_i);
    int get_i_in_indexes();
    int get_index_on_board();
    void set_index_on_board(int new_index);
    void add_fight_win();
    int get_wins();
    void forget(float forgetting_factor);
};
