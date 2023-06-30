#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>

#include <functional>

#include "Window.h"

class Button {
   public:
    Button(Window *, SDL_Surface *);
    Button(Window *, SDL_Surface *, SDL_Surface *);
    Button(Window *, SDL_Surface *, SDL_Surface *, SDL_Surface *);
    SDL_Rect buttonRect;
    SDL_Rect getPosition();
    void renderButton(SDL_Surface *);
    void onClick();
    void setPosition(SDL_Rect pos);
    void update(SDL_Event &e, const std::function<void()> &clicked);
    void end();

   private:
    SDL_Surface *_windowSurface = NULL;
    SDL_Surface *_normalSurface = NULL;
    SDL_Surface *_hoveredSurface = NULL;
    SDL_Surface *_clickedSurface = NULL;
    SDL_Texture *_buttonNormalTexture = NULL;
    SDL_Texture *_buttonClickedTexture = NULL;
    SDL_Texture *_buttonHoveredTexture = NULL;
    SDL_Renderer *_renderer;
    SDL_Rect _position;
    Window *_mainWindow = NULL;
};

#endif