#pragma once

#include <SDL2/SDL_render.h>

namespace engine {

struct Texture {
    SDL_Texture *sdl_texture;
    int width;
    int height;
};

}