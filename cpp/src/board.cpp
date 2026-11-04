#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <algorithm>

#include "board.h"


Board::Board(int in_edge_len) {
    edge_len = in_edge_len;
    total_nodes = in_edge_len*in_edge_len;
    Board::create_empty_board_fields();
}

Board::Board(int in_edge_len, float appear_prob) {
    edge_len = in_edge_len;
    total_nodes = in_edge_len*in_edge_len;
    create_empty_board_fields();
    fill_board_knights(appear_prob);
}


void Board::create_empty_board_fields() {
    board_fields.resize(total_nodes);
    for(int i=0; i<total_nodes; i++) {
        board_fields[i] = new BoardNode(false);
    }
}

void Board::fill_board_knights(float appear_prob) {
    if (appear_prob<0 || appear_prob>1) {
        throw std::invalid_argument("Argument is not a value between 0 and 1!!");
    }

    std::vector<int> knight_indexes(total_nodes);
    std::iota(knight_indexes.begin(), knight_indexes.end(), 0);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(knight_indexes.begin(), knight_indexes.end(), gen);

    int numof_knights = std::round(total_nodes*appear_prob);
    knight_nodes_adresses.resize(numof_knights);
    total_knights = numof_knights;

    for (int i=total_nodes-1; i>=numof_knights; i--) {
        knight_indexes.erase(knight_indexes.begin() + i);
    }
    sort(knight_indexes.begin(), knight_indexes.end());

    for (int i; i<knight_indexes.size(); i++) {
        int knight_index = knight_indexes[i];
        board_fields[knight_index]->set_is_knight(true);
        board_fields[knight_index]->set_i_in_indexes(i);
        knight_nodes_adresses[i] = board_fields[knight_index];
    }
}


void Board::print_board_sqared() {
    for (int i=0; i<total_nodes; i+=edge_len) {
        if ((i+1)%edge_len == 0) std::cout<<std::endl;

        for (int j=i; j<i+edge_len; j++) {
            int node_val = 0;
            if (board_fields[j]->get_is_knight()) node_val++;
            std::cout<<node_val<<" ";
        }
        std::cout<<std::endl;
    }
}

void Board::print_board_trianglar() {
    int node_val = 0;
    for (int i=0; i<total_nodes; i+=edge_len*2) {
        std::cout<<" ";
        int j=i;
        while (j<i+edge_len) {
            if (board_fields[j]->get_is_knight()) node_val++;
            std::cout<<node_val<<" ";
            node_val = 0;
            j++;
        }
        std::cout<<std::endl;

        if (i+1<total_nodes-edge_len) {
            for (int k=j; k<j+edge_len; k++) {
                if (board_fields[k]->get_is_knight()) node_val++;
                std::cout<<node_val<<" ";
                node_val = 0;
            }
            std::cout<<std::endl;
        }
    }
}

void Board::print_board_trianglar_netted() {
    int node_val = 0;

    for (int i=0; i<total_nodes; i+=edge_len*2) {
        std::cout<<"  "<<node_val;
        if (board_fields[i]->get_is_knight()) node_val++;
        node_val = 0;

        int j=i;
        while (j+1<i+edge_len) {
            if (board_fields[j]->get_is_knight()) node_val++;
            std::cout<<" - "<<node_val;
            node_val = 0;
            j++;
        }

        if (i+1<total_nodes-edge_len) {
            std::string somestring = "  ʌ";
            for (int l=0; l<edge_len-2; l++) somestring += "   ʌ";
            somestring += "  /";
            std::cout<<std::endl<<somestring<<std::endl;

            if (board_fields[j]->get_is_knight()) node_val++;
            std::cout<<node_val;
            node_val = 0;

            for (int k=j+1; k<j+edge_len; k++) {
                if (board_fields[k]->get_is_knight()) node_val++;
                std::cout<<" - "<<node_val;
                node_val = 0;
            }

            if (j+edge_len+1<total_nodes){
                std::string somestring = "  v";
                for (int l=0; l<edge_len-2; l++) {
                    somestring += "   v";
                }
                somestring += "  \\";
                std::cout<<std::endl<<somestring;
            }
            std::cout<<std::endl;
        }
    }
}

void Board::print_neighbors(int index) {
    int* neighbors = get_neighbors(index);
    for (int i=0; i<neighbors_count; i++) {
        std::cout<<neighbors[i]<<" ";
    }
    std::cout<<std::endl;
}

void Board::print_knight_nodes() {
    std::cout<<"Address\n";
    for (BoardNode* curr_node_index:knight_nodes_adresses) {
        std::cout<<curr_node_index<<std::endl;
    }
}

void Board::print_knight_indexes() {
    for (int i=0; i<knight_nodes_indexes.size(); i++) {
        std::cout<<knight_nodes_indexes[i]<<" ";
    }
    std::cout<<std::endl;
}

int Board::get_node_index(BoardNode* node_ptr) {
    int index = static_cast<int>(node_ptr - board_fields.data());
    return index;
}

int* Board::get_neighbors(int index) {
    static int neighbors[neighbors_count];

    neighbors[0] = (index - edge_len + total_nodes)%25;
    neighbors[1] = (index - edge_len + total_nodes)%25 + 1 - ((index+1)%edge_len == 0)*edge_len;
    neighbors[2] = index - 1 + ((index+edge_len)%edge_len == 0)*edge_len;
    neighbors[3] = index + 1 - ((index+1)%edge_len == 0)*edge_len;
    neighbors[4] = (index + edge_len)%25 - 1 + ((index+edge_len)%edge_len == 0)*edge_len;
    neighbors[5] = (index + edge_len)%25;
    return neighbors;
}

int Board::get_random_neighbor(int index) {
    int* neighbors = get_neighbors(index);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 5);
    int neighbor_index = neighbors[dist6(rng)];
    return neighbor_index;
}

void Board::swap_nodes(int node_i1, int node_i2) {
    std::swap(board_fields[node_i1], board_fields[node_i2]);
}

void Board::swap_knight_with_empty(int i_knight, int i_node, int knight_index_i) {
    std::swap(board_fields[i_knight], board_fields[i_node]);
    knight_nodes_indexes[knight_index_i] = i_node;
}

void Board::swap_knights(int i_knight1, int i_knight2, int knight1_index_i) {
    knight_nodes_indexes[knight1_index_i] = i_knight2;

    int knight2_index_i = board_fields[i_knight2].get_i_in_indexes();
    knight_nodes_indexes[knight2_index_i] = i_knight1;
    std::swap(board_fields[i_knight1], board_fields[i_knight2]);
}

float Board::calc_winning_prob(int wins_k1, int wins_k2, float control_param=1) {
    return 1/(1+control_param*exp(wins_k2-wins_k1));
}

void Board::move_all_knights(bool forget_now, float forgetting_factor=0.1) {
    // std::cout<<"Am I forgetting: "<<forget_now<<std::endl;
    for (int i=0; i<total_knights; i++) {
        int knight_index = knight_nodes_indexes[i];
        int target_index = get_random_neighbor(knight_index);

        if (board_fields[target_index].get_is_knight()) {
            float knight_winning_prob = calc_winning_prob(
                board_fields[knight_index].get_wins(),
                board_fields[target_index].get_wins());
            knight_winning_prob *= 1000;
            // std::cout<<knight_winning_prob<<std::endl;

            int rand_num = rand() % 1001;  //0 and 1000 inclusive
            bool fight_won_flag = (rand_num<=knight_winning_prob);
            // std::cout<<fight_won_flag<<std::endl;
            if (fight_won_flag) {
                board_fields[knight_index].add_fight_win();
                swap_knights(knight_index, target_index, i);
            }
        } else {
            swap_knight_with_empty(knight_index, target_index, i);
        }
    }

    if (forget_now) {
        for (int i=0; i<total_knights; i++) {
            int knight_index = knight_nodes_indexes[i];
            board_fields[knight_index].forget(forgetting_factor);
        }
    }
}

void Board::move_all_knights_n(int n, int forget_after_N_steps, float forgetting_factor) {
    for (int i=0; i<n; i++) {
        bool perform_forgetting;
        if (!(i%forget_after_N_steps)) perform_forgetting = true;
        else perform_forgetting = false;
        move_all_knights(perform_forgetting, forgetting_factor);
    }
}
