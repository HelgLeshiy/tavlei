#include <SDL2/SDL_events.h>
#include <memory>
#include "app.hpp"
#include "../engine/engine.hpp"

namespace framework {

App::App(Configuration&& config)
    : config_(config) { }

void App::Run(std::unique_ptr<BaseState> root_state) {
    InitSubsystems();

    PushState(std::move(root_state));

    bool exit = false;
    SDL_Event event;

    while(!exit) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                exit = true;
            }

            states_.top()->HandleEvent(&event);
        }
        renderer_->Clear();

        states_.top()->Update(1.f);
        states_.top()->OnRender(renderer_);

        renderer_->Present();
    }

    engine::destroy_sdl_subsystems();
}

void App::PushState(std::unique_ptr<BaseState> state) {
    state->SetStateContainer(this);
    state->OnInit(renderer_);
    states_.push(std::move(state));
}

void App::PopState() {
    states_.top()->OnDestroy();
    states_.pop();
}

void App::InitSubsystems() {
    engine::init_sdl_subsystems();
    window_ = std::make_shared<engine::Window>(config_.window_name, config_.window_width, config_.window_height, config_.window_flags);
    renderer_ = window_->CreateRenderer();
    renderer_->SetClearColor({30, 30, 30, 255});
}

void App::HandleEvent(SDL_Event* event) {
    states_.top()->HandleEvent(event);
}


} // namespace framework