#pragma once

#include "../framework/base_state.hpp"
#include <SDL2/SDL_events.h>
#include <algorithm>
#include <iostream>
#include <memory>
#include <optional>
#include <vector>
#include "../game/tavlei.hpp"
#include "../engine/window.hpp"

namespace tavlei {
namespace states {
class RootState : public framework::BaseState {
public:
    RootState() { }
    virtual ~RootState() { }

private:
    virtual void OnInit(std::shared_ptr<engine::Renderer> renderer) override {
        background_texture_ = renderer->LoadTexture("assets/phantasyMap.jpg");
        white_texture_ = renderer->LoadTexture("assets/whiteImg.png");
        black_texture_ = renderer->LoadTexture("assets/blackimg.png");
        prince_texture_ = renderer->LoadTexture("assets/hnefiImg.png");
        shadow_texture_ = renderer->LoadTexture("assets/shadow.png");
    }

    void OnRender(const std::shared_ptr<engine::Renderer> &renderer) override {
        int width = renderer->GetWindow()->GetScreenWidth();
        int height = renderer->GetWindow()->GetScreenHeight();
        int offset = 21;
        cell_width_ = 47 * width / background_texture_->width;
        cell_height_ = 44 * height / background_texture_->height;

        offset_x_ = offset * width / background_texture_->width;
        offset_y_ = offset * height / background_texture_->height;

        engine::Rect screen_rect = {0, 0, width, height};
        renderer->DrawTexture(background_texture_, screen_rect);

        for(auto& figure : game_.GetFigures()) {
            if(&figure == dragged_fugure_)
                continue;
            std::optional<std::shared_ptr<engine::Texture>> texture;
            if(figure.team == Team::Attackers) {
                texture = black_texture_;
            } else {
                if(figure.type == FigureType::Simple) {
                    texture = white_texture_;
                } else {
                    texture = prince_texture_;
                }
            }

            if(texture.has_value()) {
                int x = 0;
                int y = 0;

                x = offset_x_ + figure.position.x * cell_width_;
                y = offset_y_ + figure.position.y * cell_height_;

                engine::Rect figure_rect {x, y, cell_width_, cell_height_};
                renderer->DrawTexture(*texture, figure_rect);

            }
        }

        if(dragged_fugure_ != nullptr) {
            std::optional<std::shared_ptr<engine::Texture>> texture;
            if(dragged_fugure_->team == Team::Attackers) {
                texture = black_texture_;
            } else {
                if(dragged_fugure_->type == FigureType::Simple) {
                    texture = white_texture_;
                } else {
                    texture = prince_texture_;
                }
            }

            if(texture.has_value()) {
                int x = dragged_figure_x - cell_width_ / 2;
                int y = dragged_figure_y - cell_height_ / 2;

                engine::Rect figure_rect {x, y, cell_width_, cell_height_};

                renderer->DrawTexture(shadow_texture_, {figure_rect.x - 15, figure_rect.y - 15, figure_rect.w + 30, figure_rect.h + 30});

                renderer->DrawTexture(*texture, figure_rect);

            }
        }
    }

    void Update(float deltaTime) override {

    }

    void HandleEvent(SDL_Event *event) override {
        switch(event->type) {
            case SDL_MOUSEBUTTONDOWN: {
                int col = (event->button.x - offset_x_) / cell_width_;
                int row = (event->button.y - offset_y_) / cell_height_;

                std::cout << col << " " << row << "\n";

                Figure* finded_figure = nullptr;
                for(auto& figure : game_.GetFigures()) {
                    if(figure.position.x == col && figure.position.y == row) {
                        finded_figure = &figure;
                        break;
                    }
                }

                if(finded_figure != nullptr) {
                    dragged_fugure_ = finded_figure;
                    dragged_figure_x = event->button.x;
                    dragged_figure_y = event->button.y;
                }

                break;
            }
            case SDL_MOUSEBUTTONUP: {
                if(dragged_fugure_ != nullptr) {
                    int col = (event->button.x - offset_x_) / cell_width_;
                    int row = (event->button.y - offset_y_) / cell_height_;

                    if(col == 11 || row == 11) {
                        auto& figures = game_.GetFigures();
                        figures.erase(std::find_if(figures.begin(), figures.end(), [this](Figure& fig){ return &fig == dragged_fugure_; }));
                        dragged_fugure_ = nullptr;
                        break;
                    }

                    Figure* finded_figure = nullptr;
                    for(auto& figure : game_.GetFigures()) {
                        if(&figure == dragged_fugure_)
                            continue;

                        if(figure.position.x == col && figure.position.y == row) {
                            finded_figure = &figure;
                            break;
                        }
                    }

                    if(finded_figure == nullptr) {
                        dragged_fugure_->position.x = col;
                        dragged_fugure_->position.y = row;
                    }

                    dragged_fugure_ = nullptr;

                }
                break;
            }
            case SDL_MOUSEMOTION: {
                dragged_figure_x = event->motion.x;
                dragged_figure_y = event->motion.y;
                break;
            }
        }
    }

    int offset_x_;
    int offset_y_;
    int cell_width_;
    int cell_height_;

    tavlei::Tavlei game_;
    std::shared_ptr<engine::Texture> background_texture_;
    std::shared_ptr<engine::Texture> white_texture_;
    std::shared_ptr<engine::Texture> black_texture_;
    std::shared_ptr<engine::Texture> prince_texture_;
    std::shared_ptr<engine::Texture> shadow_texture_;

    Figure* dragged_fugure_ = nullptr;
    int dragged_figure_x = 0;
    int dragged_figure_y = 0;
};
}
}