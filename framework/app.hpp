#pragma once

#include <SDL2/SDL.h>
#include <memory>
#include <stack>
#include <string>

#include "base_state.hpp"
#include "state_container.hpp"

namespace framework {

struct Configuration {
    std::string window_name;
    int window_width;
    int window_height;
    Uint32 window_flags;
};

class App : public StateContainer {
public:
    App(Configuration&& config);

    void Run(std::unique_ptr<BaseState> root_state);

    virtual void PushState(std::unique_ptr<BaseState> state) override;
    virtual void PopState() override;
    
private:
    void InitSubsystems();
    void HandleEvent(SDL_Event* event);

private:
    std::stack<std::unique_ptr<BaseState>> states_;
    Configuration config_;
    std::shared_ptr<engine::Renderer> renderer_;
    std::shared_ptr<engine::Window> window_;
};

} // namespace framework