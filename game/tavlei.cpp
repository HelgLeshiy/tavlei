#include "tavlei.hpp"

namespace tavlei {

Tavlei::Tavlei() {
    ResetGame();
}

void Tavlei::ResetGame() {
    figures_.reserve(25);
    figures_.emplace_back(FigureType::Prince, Team::Defenders, Vector2d{5, 5});
    figures_.emplace_back(FigureType::Simple, Team::Defenders, Vector2d{4, 5});
    figures_.emplace_back(FigureType::Simple, Team::Defenders, Vector2d{3, 5});
    figures_.emplace_back(FigureType::Simple, Team::Defenders, Vector2d{6, 5});
    figures_.emplace_back(FigureType::Simple, Team::Defenders, Vector2d{7, 5});
    figures_.emplace_back(FigureType::Simple, Team::Defenders, Vector2d{5, 4});
    figures_.emplace_back(FigureType::Simple, Team::Defenders, Vector2d{5, 3});
    figures_.emplace_back(FigureType::Simple, Team::Defenders, Vector2d{5, 6});
    figures_.emplace_back(FigureType::Simple, Team::Defenders, Vector2d{5, 7});

    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{0, 3});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{0, 4});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{0, 5});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{0, 6});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{0, 7});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{1, 5});


    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{10, 3});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{10, 4});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{10, 5});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{10, 6});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{10, 7});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{9, 5});


    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{3, 0});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{4, 0});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{5, 0});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{6, 0});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{7, 0});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{5, 1});

    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{3, 10});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{4, 10});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{5, 10});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{6, 10});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{7, 10});
    figures_.emplace_back(FigureType::Simple, Team::Attackers, Vector2d{5, 9});
}

}