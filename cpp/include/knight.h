#pragma once

#include "team.hpp"


class Knight {
private:
    int wins;
    int total_fights;
    Team team;

public:
    Knight();
    Knight(Team in_team);

    void set_team(Team in_team);
    Team get_team();
};
