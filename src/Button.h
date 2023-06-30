#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>

#include <functional>

#include "Window.h"

enum class ButtonState { Normal, Hovered, Clicked };

class Button {
   public:
    Button(Window *window, SDL_Rect pos, SDL_Surface *normalSurface);
    Button(Window *window, SDL_Rect pos, SDL_Surface *normalSurface, SDL_Surface *clickedSurface);
    Button(Window *window, SDL_Rect pos, SDL_Surface *normalSurface, SDL_Surface *clickedSurface,
           SDL_Surface *HoveredSurface);
    SDL_Rect buttonRect;
    void renderButton(SDL_Surface *);
    void onClick();
    void setPosition(SDL_Rect pos);
    SDL_Rect getPosition();
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
    bool _buttonHovered = false;
    void _manageHover(SDL_Event &e);
    bool _isClicked(SDL_Event &e);
    bool _isCursorWithin();
    ButtonState _buttonState = ButtonState::Normal;
};

#endif