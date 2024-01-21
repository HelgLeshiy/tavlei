#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <memory>

#include "../engine/renderer.hpp"
#include "state_container.hpp"

namespace framework {

class App;
class BaseState {
public:
    BaseState() { }
    virtual ~BaseState() { }
    
    virtual void OnInit(std::shared_ptr<engine::Renderer> renderer) { }
    virtual void OnDestroy() { }
    virtual void OnRender(const std::shared_ptr<engine::Renderer>& renderer) { }
    virtual void Update(float deltaTime) { }
    virtual void HandleEvent(SDL_Event* event) { }

    void SetStateContainer(StateContainer* state_container) {
        state_container_ = state_container;
    }

protected:
    void PushState(std::unique_ptr<BaseState> state) {
        state_container_->PushState(std::move(state));
    }

    void PopState() {
        state_container_->PopState();
    }

private:
    StateContainer* state_container_;
};

} // namespace framework