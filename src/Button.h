#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>

class Button {
   public:
    Button(SDL_Renderer *, SDL_Surface *);
    Button(SDL_Renderer *, SDL_Surface *, SDL_Surface *);
    Button(SDL_Renderer *, SDL_Surface *, SDL_Surface *, SDL_Surface *);
    void renderButton(SDL_Surface *);

   private:
    SDL_Surface *_normalSurface = NULL;
    SDL_Surface *_hoveredSurface = NULL;
    SDL_Surface *_clickedSurface = NULL;
    SDL_Renderer *_renderer;
    SDL_Rect buttonRect;
};

#endif