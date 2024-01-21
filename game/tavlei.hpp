#pragma once

#include "common.hpp"
#include "figure.hpp"
#include <vector>

namespace tavlei {
class Tavlei {
public:
    Tavlei();
    std::vector<Figure>& GetFigures() { return figures_; }
private:
    void ResetGame();


private:
    std::vector<Figure> figures_;
};
} // namespace tavlei