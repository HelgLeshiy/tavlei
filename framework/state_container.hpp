#pragma once

#include <memory>

namespace framework {

class BaseState;

class StateContainer {
public:
    virtual void PushState(std::unique_ptr<BaseState> state) = 0;
    virtual void PopState() = 0;
};

} // namespace framework