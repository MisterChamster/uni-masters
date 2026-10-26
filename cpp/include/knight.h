#pragma once

#include "team.hpp"


class Knight {
private:
    int wins;
    int total_fights;
    Team team;

public:
    Knight();
    // Knight(std::string in_team);
    Knight(Team in_team);
};
