#pragma once


class BoardNode {
private:
    bool is_knight;
    int wins;
    int total_fights;
    int i_in_indexes;

public:
    BoardNode();
    BoardNode(bool in_is_knight);

    void set_is_knight(bool in_is_knight);
    bool get_is_knight();
    void set_i_in_indexes(int in_i);
    int get_i_in_indexes();
};
