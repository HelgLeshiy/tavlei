#pragma once

#include "window.hpp"
#include "renderer.hpp"
#include "sdl_exception.hpp"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_video.h>
#include <memory>

namespace engine {

Window::Window(const std::string& name, int width, int height, unsigned int flags) {
    Create(name, width, height, flags);
}

Window::~Window() { }

void Window::Create(const std::string& name, int width, int height, unsigned int flags) {
    Uint32 res_flags = 0;

    if(flags & INVISBLE) {
        res_flags |= SDL_WINDOW_HIDDEN;
    } else {
        res_flags |= SDL_WINDOW_SHOWN;
    }

    if(flags & FULLSCREEN) {
        res_flags |= SDL_WINDOW_FULLSCREEN;
    }

    if(flags & BORDERLESS) {
        res_flags |= SDL_WINDOW_BORDERLESS;
    }

    screen_width_ = width;
    screen_height_ = height;

    sdl_window_ = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width_, screen_height_, res_flags);

    if(sdl_window_ == nullptr) {
        raise_sdl_exception("SDL Window could not be created");
    }
}

void Window::Destroy() {
    SDL_DestroyWindow(sdl_window_);
    sdl_window_ = nullptr;
}

std::shared_ptr<Renderer> Window::CreateRenderer() {
    return std::make_shared<Renderer>(this);
}
}