#include <iostream>

#include "knight.h"


Knight::Knight() {
    team = Team::placeholder;
    wins = 0;
    total_fights = 0;
}

Knight::Knight(Team in_team) {
    team = in_team;
    wins = 0;
    total_fights = 0;
}

void Knight::set_team(Team in_team) {
    team = in_team;
}

Team Knight::get_team() {
    return team;
}
