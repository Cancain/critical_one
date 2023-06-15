#include "Button.h"

#include <iostream>

Button::Button(SDL_Renderer *renderer, SDL_Surface *normalSurface, SDL_Surface *clickedSurface,
               SDL_Surface *hoveredSurface) {
    _renderer = renderer;
    _normalSurface = normalSurface;
    _clickedSurface = clickedSurface;
    _hoveredSurface = hoveredSurface;
}

Button::Button(SDL_Renderer *renderer, SDL_Surface *normalSurface, SDL_Surface *clickedSurface) {
    _renderer = renderer;
    _normalSurface = normalSurface;
    _clickedSurface = clickedSurface;
}

Button::Button(SDL_Renderer *renderer, SDL_Surface *normalSurface) {
    _renderer = renderer;
    _normalSurface = normalSurface;
}

void Button::renderButton(SDL_Surface *windowSurface) {
    SDL_Texture *buttonClickedTexture = NULL;
    SDL_Texture *buttonHoveredTexture = NULL;

    if (!_normalSurface) {
        printf("Failed to load button surface: %s\n", SDL_GetError());
    }
    if (_clickedSurface != NULL) {
        buttonClickedTexture = SDL_CreateTextureFromSurface(_renderer, _clickedSurface);
    }

    if (_hoveredSurface != NULL) {
        buttonHoveredTexture = SDL_CreateTextureFromSurface(_renderer, _clickedSurface);
    }

    SDL_Texture *buttonNormalTexture = SDL_CreateTextureFromSurface(_renderer, _normalSurface);

    SDL_Rect buttonRect;
    buttonRect.w = _normalSurface->w;
    buttonRect.h = _normalSurface->h;

    SDL_Rect pos = {x : (800 / 2) - buttonRect.w / 2, y : (600 / 2) - buttonRect.h};
    SDL_BlitSurface(_normalSurface, NULL, windowSurface, &pos);

    SDL_FreeSurface(_normalSurface);
    SDL_FreeSurface(_clickedSurface);
    SDL_FreeSurface(_hoveredSurface);
    SDL_DestroyTexture(buttonNormalTexture);
    SDL_DestroyTexture(buttonClickedTexture);
    SDL_DestroyTexture(buttonHoveredTexture);
};
