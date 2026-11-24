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

    void add_fight_win();
    void forget(float forgetting_factor);
    std::string get_wins_to_print(std::string midspace_char = " ");

    bool get_is_knight();
    void set_is_knight(bool in_is_knight);
    int get_i_in_indexes();
    void set_i_in_indexes(int in_i);
    int get_index_on_board();
    void set_index_on_board(int new_index);
    int get_wins();
};
