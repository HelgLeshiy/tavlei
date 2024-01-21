#pragma once

#include "common.hpp"
#include "texture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <memory>
#include <string>
namespace engine {

class Window;
class Renderer {
public:
    Renderer(Window* window);
    ~Renderer();

    void Present();
    void Clear();
    void SetClearColor(Color color);
    
    void Rectangle(const Rect& rect, Color color);

    std::shared_ptr<Texture> LoadTexture(const std::string& path);

    void DrawTexture(std::shared_ptr<Texture> texture, const Rect& rect);

    Window* GetWindow() { return window_; }

private:
    void SetDrawColor(Color color);

private:

    void Init(SDL_Window *win);

private:
    SDL_Renderer *sdl_renderer_;
    Color clear_color_;
    Window* window_;

    friend class Window;
};
}