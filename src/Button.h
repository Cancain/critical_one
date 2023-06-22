#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>

#include <functional>

class Button {
   public:
    Button(SDL_Renderer *, SDL_Surface *);
    Button(SDL_Renderer *, SDL_Surface *, SDL_Surface *);
    Button(SDL_Renderer *, SDL_Surface *, SDL_Surface *, SDL_Surface *);
    SDL_Rect buttonRect;
    SDL_Rect getPosition();
    void renderButton(SDL_Surface *);
    void onClick();
    void setPosition(SDL_Rect pos);
    void update(SDL_Event &e, const std::function<void()> &clicked);

   private:
    SDL_Surface *_normalSurface = NULL;
    SDL_Surface *_hoveredSurface = NULL;
    SDL_Surface *_clickedSurface = NULL;
    SDL_Renderer *_renderer;
    SDL_Rect _position;
};

#endif