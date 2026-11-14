#include <iostream>
#include "board.h"

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
