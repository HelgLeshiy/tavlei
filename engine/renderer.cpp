#include "renderer.hpp"
#include "sdl_exception.hpp"
#include "texture.h"
#include <SDL2/SDL_blendmode.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <iostream>
#include <memory>
#include "window.hpp"

namespace engine {

Renderer::Renderer(Window* window)
    : window_(window), clear_color_({0, 0, 0, 255}) {
    Init(window_->GetRawWindow());
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(sdl_renderer_);
    sdl_renderer_ = nullptr;
}

void Renderer::Init(SDL_Window *win) {
    sdl_renderer_ = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if(sdl_renderer_ == nullptr) {
        raise_sdl_exception("Can not create renderer");
    }

    SDL_SetRenderDrawBlendMode(sdl_renderer_, SDL_BLENDMODE_BLEND);
}

void Renderer::Present() {
    SDL_RenderPresent(sdl_renderer_);
}

void Renderer::Clear() {
    SetDrawColor(clear_color_);
    SDL_RenderClear(sdl_renderer_);
}

void Renderer::SetClearColor(Color color) {
    clear_color_ = color;
}
    
void Renderer::Rectangle(const Rect& rect, Color color) {
    SetDrawColor(color);
    SDL_Rect sdl_rect {rect.x, rect.y, rect.w, rect.h};
    SDL_RenderFillRect(sdl_renderer_, &sdl_rect);
}

void Renderer::SetDrawColor(Color color) {
    SDL_SetRenderDrawColor(sdl_renderer_, color.r, color.g, color.b, color.a);
}

std::shared_ptr<Texture> Renderer::LoadTexture(const std::string& path) {
    SDL_Surface* surf = IMG_Load(path.c_str());

    if(surf == nullptr) {
        raise_sdl_exception("Cannot load texture path=" + path);
    }

    int w = surf->w;
    int h = surf->h;

    SDL_Texture* tex = SDL_CreateTextureFromSurface(sdl_renderer_, surf);
    if(tex == nullptr) {
        raise_sdl_exception("Cannot create texture path=" + path);
    }

    SDL_FreeSurface(surf);

    return std::shared_ptr<Texture>(new Texture{tex, w, h});
}

void Renderer::DrawTexture(std::shared_ptr<Texture> texture, const Rect& rect) {
    SDL_Rect sdl_rect{rect.x, rect.y, rect.w, rect.h};
    SDL_RenderCopy(sdl_renderer_, texture->sdl_texture, nullptr, &sdl_rect);
}

}