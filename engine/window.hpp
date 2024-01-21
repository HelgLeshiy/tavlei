#pragma once
#include "renderer.hpp"
#include <SDL2/SDL.h>

#include <memory>
#include <string>

namespace engine {

enum WindowFlags { INVISBLE = 0x1, FULLSCREEN = 0x2, BORDERLESS = 0x4 };

class Window {
public:
	Window(const std::string& name, int width, int height, unsigned int flags);
	~Window();

	int GetScreenWidth() const { return screen_width_; }
	int GetScreenHeight() const { return screen_height_; }

    SDL_Window* GetRawWindow() { return sdl_window_; }

    std::shared_ptr<Renderer> CreateRenderer();
private:
    void Create(const std::string& name, int width, int height, unsigned int flags);
    void Destroy();

private:
	SDL_Window *sdl_window_;
	int screen_height_, screen_width_;
};

}