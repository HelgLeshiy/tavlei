#include "engine.hpp"
#include "sdl_exception.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

namespace engine {
    int init_sdl_subsystems()
    {
        if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            raise_sdl_exception("Can't init SDL");
        }

        if(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
            raise_sdl_exception("Can't init IMG");
        }

        if(TTF_Init() != 0) {
            raise_sdl_exception("Can't init TTF");
        }

        if(Mix_Init(MIX_INIT_OGG) == 0) {
            raise_sdl_exception("Can't init MIX");
        }

        SDL_SetHint (SDL_HINT_RENDER_SCALE_QUALITY, "linear");

        return 0;
    }

    int destroy_sdl_subsystems()
    {
        Mix_Quit();
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();

        return 0;
    }
}