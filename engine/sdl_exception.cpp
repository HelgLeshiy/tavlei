#include "sdl_exception.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <stdexcept>

namespace engine {
    void raise_sdl_exception(const std::string& msg) {
        throw std::runtime_error(msg + ": " + SDL_GetError());
    }
}