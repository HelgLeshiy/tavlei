#pragma once

#include <SDL2/SDL_rect.h>
namespace engine {

struct Color {
    Color(unsigned char r_, unsigned char g_, unsigned char b_, unsigned char a_ = 255)
        : r(r_), g(g_), b(b_), a(a_) { }

    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

struct Rect {
    int x;
    int y;
    int w;
    int h;
};

}