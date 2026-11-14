#include <random>

#include "board.h"


// ==================== Constructors ====================
Board::Board() {
    reset_non_vectors();
}

Board::Board(int in_edge_len, float appear_prob) {
    edge_len = in_edge_len;
    total_nodes = in_edge_len*in_edge_len;
    create_empty_board_fields(total_nodes);
    fill_board_knights(appear_prob);
}


// ================ Construction helpers ================
void Board::create_empty_board_fields(int in_total_nodes) {
    board_fields.resize(in_total_nodes);
    for(int i=0; i<total_nodes; i++) {
        board_fields[i] = new BoardNode(false, i);
    }
}

void Board::fill_board_knights(float appear_prob) {
    if (appear_prob<0 || appear_prob>1) {
        throw std::invalid_argument("Argument is not a value between 0 and 1!!");
    }

    // Set total_knights field
    int numof_knights = std::round(total_nodes*appear_prob);
    total_knights = numof_knights;

    // Create list of random knight indexes
    std::vector<int> knight_indexes(total_nodes);
    std::iota(knight_indexes.begin(), knight_indexes.end(), 0);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(knight_indexes.begin(), knight_indexes.end(), gen);

    for (int i=total_nodes-1; i>=total_knights; i--) {
        knight_indexes.erase(knight_indexes.begin() + i);
    }
    sort(knight_indexes.begin(), knight_indexes.end());

    // Set nodes to knights trough board_fields and
    // fill knight_nodes_adresses with knight pointers
    knight_nodes_adresses.resize(numof_knights);
    for (int i=0; i<knight_indexes.size(); i++) {
        int knight_index = knight_indexes[i];
        board_fields[knight_index]->set_is_knight(true);
        board_fields[knight_index]->set_i_in_indexes(i);
        knight_nodes_adresses[i] = board_fields[knight_index];
    }
}


// ===================== Resetters =====================
void Board::reset_vector_fields() {
    for (BoardNode* ptr : board_fields)
        delete ptr;

    std::vector<BoardNode*>().swap(board_fields);
    std::vector<BoardNode*>().swap(knight_nodes_adresses);
}

void Board::reset_non_vectors() {
    edge_len = 0;
    total_nodes = 0;
    total_knights = 0;
}

void Board::reset_board() {
    reset_non_vectors();
    reset_vector_fields();
}

// =================== Reconstructors ===================
void Board::reconstruct(int in_edge_len, float appear_prob) {
    reset_board();
    edge_len = in_edge_len;
    total_nodes = in_edge_len*in_edge_len;
    create_empty_board_fields(total_nodes);
    fill_board_knights(appear_prob);
}
