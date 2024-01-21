#pragma once

#include "common.hpp"

namespace tavlei {
enum class FigureType {
    Simple,
    Prince
};
enum class Team {
    Defenders,
    Attackers
};
struct Figure {
    Figure(FigureType type_, Team team_, Vector2d position_)
        : type(type_), team(team_), position(position_) { }

    FigureType type;
    Team team;
    Vector2d position;
};
} // namespace tavlei