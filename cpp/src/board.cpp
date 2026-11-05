#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <algorithm>

#include "board.h"


Board::Board(int in_edge_len) {
    edge_len = in_edge_len;
    total_nodes = in_edge_len*in_edge_len;
    total_knights = 0;
    sigma = 0.5;
    Board::create_empty_board_fields();
}

Board::Board(int in_edge_len, float appear_prob) {
    edge_len = in_edge_len;
    total_nodes = in_edge_len*in_edge_len;
    sigma = 0.5;
    create_empty_board_fields();
    fill_board_knights(appear_prob);
}


void Board::create_empty_board_fields() {
    board_fields.resize(total_nodes);
    for(int i=0; i<total_nodes; i++) {
        board_fields[i] = new BoardNode(false, i);
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

    for (int i=0; i<knight_indexes.size(); i++) {
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
        if (board_fields[i]->get_is_knight()) node_val++;
        std::cout<<"  "<<node_val;
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

std::string get_num_to_print(BoardNode* node_adress, std::string empty_char = " ") {
    if (node_adress->get_is_knight()) {
        std::string stringed_num = std::to_string(node_adress->get_wins());

        if      (stringed_num.length() == 1) return " " + stringed_num + " ";
        else if (stringed_num.length() == 2) return " " + stringed_num;
        else                                 return stringed_num;
    }
    else return " " + empty_char + " ";
}

void Board::print_board_trianglar_wins(std::string empty_char) {
    std::string num_to_print;

    for (int i=0; i<total_nodes; i+=edge_len*2) {
        num_to_print = get_num_to_print(board_fields[i], empty_char);
        std::cout<<"  "<<num_to_print;

        int j=i;
        while (j+1<i+edge_len) {
            num_to_print = get_num_to_print(board_fields[j], empty_char);
            std::cout<<" "<<num_to_print;
            j++;
        }

        if (i+1<total_nodes-edge_len) {
            num_to_print = get_num_to_print(board_fields[j], empty_char);
            std::cout<<std::endl<<std::endl<<num_to_print;

            for (int k=j+1; k<j+edge_len; k++) {
                num_to_print = get_num_to_print(board_fields[k], empty_char);
                std::cout<<" "<<num_to_print;
            }

            if (j+edge_len+1<total_nodes) std::cout<<std::endl;
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
    for (BoardNode* curr_node_address:knight_nodes_adresses) {
        std::cout<<curr_node_address<<std::endl;
    }
}


int* Board::get_neighbors(int index) {
    static int neighbors[neighbors_count];

    neighbors[0] = (index - edge_len + total_nodes)%total_nodes;
    neighbors[1] = (index - edge_len + total_nodes)%total_nodes + 1 - ((index+1)%edge_len == 0)*edge_len;
    neighbors[2] = index - 1 + ((index+edge_len)%edge_len == 0)*edge_len;
    neighbors[3] = index + 1 - ((index+1)%edge_len == 0)*edge_len;
    neighbors[4] = (index + edge_len)%total_nodes - 1 + ((index+edge_len)%edge_len == 0)*edge_len;
    neighbors[5] = (index + edge_len)%total_nodes;
    return neighbors;
}

int Board::get_random_neighbor(int index) {
    int* neighbors = get_neighbors(index);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 5);
    int neighbor_index = dist6(rng);
    return neighbors[neighbor_index];
}

void Board::swap_knight_with_empty(int i_knight, int i_node) {
    board_fields[i_knight]->set_index_on_board(i_node);
    std::swap(board_fields[i_knight], board_fields[i_node]);
}

void Board::swap_knights(int i_knight1, int i_knight2) {
    board_fields[i_knight1]->set_index_on_board(i_knight2);
    board_fields[i_knight2]->set_index_on_board(i_knight1);
    std::swap(board_fields[i_knight1], board_fields[i_knight2]);
}

double Board::calc_winning_prob(int wins_k1, int wins_k2, float control_param) {
    return 1/(1+control_param*exp(wins_k2-wins_k1));
}

double Board::calc_sigma_2pow() {
    double winning_probs_sum = 0;
    double winning_probs_2pow_sum = 0;

    for (int i=0; i<total_knights-1; i++) {
        int wins_first = knight_nodes_adresses[i]->get_wins();
        int wins_targ = knight_nodes_adresses[i+1]->get_wins();
        double winning_prob = calc_winning_prob(wins_first, wins_targ, sigma);

        winning_probs_sum += winning_prob;
        winning_probs_2pow_sum += winning_prob*winning_prob;
    }
    double winning_prob = calc_winning_prob(
        knight_nodes_adresses[total_knights-1]->get_wins(),
        knight_nodes_adresses[0]->get_wins(),
        sigma);
    winning_probs_sum += winning_prob;
    winning_probs_2pow_sum += winning_prob*winning_prob;

    winning_probs_sum /= total_knights;
    winning_probs_2pow_sum /= total_knights;

    double sigma_2pow = winning_probs_2pow_sum - 
                        (winning_probs_sum*winning_probs_sum);
    return sigma_2pow;
}

void Board::move_all_knights(bool forget_now, float forgetting_factor) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    for (int i=0; i<total_knights; i++) {
        BoardNode* knight_address = knight_nodes_adresses[i];
        int knight_index = knight_address->get_index_on_board();
        int target_index = get_random_neighbor(knight_index);
        BoardNode* target_address = board_fields[target_index];

        if (target_address->get_is_knight()) {
            double knight_winning_prob = calc_winning_prob(
                knight_address->get_wins(),
                target_address->get_wins(),
                sigma);
            double rand_num_doble = dist(gen);

            bool fight_won_flag = (rand_num_doble<=knight_winning_prob);
            if (fight_won_flag) {
                knight_address->add_fight_win();
                swap_knights(knight_index, target_index);
            }
        } else {
            swap_knight_with_empty(knight_index, target_index);
        }
    }

    if (forget_now) {
        for (int i=0; i<total_knights; i++) {
            knight_nodes_adresses[i]->forget(forgetting_factor);
        }
    }
}

void Board::move_all_knights_n(int n, int forget_after_N_steps, float forgetting_factor) {
    for (int i=0; i<n; i++) {
        std::cout<<sigma<<std::endl;
        bool perform_forgetting;
        if (!(i%forget_after_N_steps)) perform_forgetting = true;
        else perform_forgetting = false;

        move_all_knights(perform_forgetting, forgetting_factor);
        double sigma_2pow = calc_sigma_2pow();
        sigma = std::sqrt(sigma_2pow);
    }
}
