#include "Button.h"

#include <iostream>

Button::Button(SDL_Renderer *renderer, SDL_Surface *normalSurface, SDL_Surface *clickedSurface,
               SDL_Surface *hoveredSurface)
    : Button(renderer, normalSurface, clickedSurface) {
    _hoveredSurface = hoveredSurface;
}

Button::Button(SDL_Renderer *renderer, SDL_Surface *normalSurface, SDL_Surface *clickedSurface)
    : Button(renderer, normalSurface) {
    _clickedSurface = clickedSurface;
}

Button::Button(SDL_Renderer *renderer, SDL_Surface *normalSurface) {
    _renderer = renderer;
    _normalSurface = normalSurface;
    buttonRect.w = _normalSurface->w;
    buttonRect.h = _normalSurface->h;
    SDL_Rect pos = {x : (800 / 2) - buttonRect.w / 2, y : (600 / 2) - buttonRect.h};
    _position = pos;
}

void Button::renderButton(SDL_Surface *windowSurface) {
    SDL_Texture *buttonClickedTexture = NULL;
    SDL_Texture *buttonHoveredTexture = NULL;

    _windowSurface = windowSurface;

    if (!_normalSurface) {
        printf("Failed to load normal button surface: %s\n", SDL_GetError());
    }
    if (_clickedSurface != NULL) {
        buttonClickedTexture = SDL_CreateTextureFromSurface(_renderer, _clickedSurface);
    }

    if (_hoveredSurface != NULL) {
        buttonHoveredTexture = SDL_CreateTextureFromSurface(_renderer, _hoveredSurface);
    }

    SDL_Texture *buttonNormalTexture = SDL_CreateTextureFromSurface(_renderer, _normalSurface);

    SDL_BlitSurface(_normalSurface, NULL, windowSurface, &_position);

    SDL_FreeSurface(_normalSurface);
    SDL_DestroyTexture(buttonNormalTexture);

    // if (_clickedSurface != NULL) {
    // SDL_FreeSurface(_clickedSurface);
    // SDL_DestroyTexture(buttonClickedTexture);
    //}

    // if (_hoveredSurface != NULL) {
    // SDL_FreeSurface(_hoveredSurface);
    // SDL_DestroyTexture(buttonHoveredTexture);
    //}
};

void Button::onClick() { printf("Button clicked!"); }

bool hovered = false;

void Button::update(SDL_Event &e, const std::function<void()> &clicked) {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    SDL_Rect pos = {x : (800 / 2) - buttonRect.w / 2, y : (600 / 2) - buttonRect.h};

    bool isHovered = mouseX >= _position.x && mouseX <= _position.x + buttonRect.w &&
                     mouseY >= _position.y && mouseY <= _position.y + buttonRect.h;

    if (isHovered && _windowSurface && !hovered) {
        printf("hovered\n");
        SDL_BlitSurface(_hoveredSurface, NULL, _windowSurface, &_position);
        hovered = true;
    } else {
        SDL_BlitSurface(_normalSurface, NULL, _windowSurface, &_position);
        printf("unhovered\n");
        hovered = false;
    }

    if (e.button.button == SDL_BUTTON_LEFT && isHovered) {
        clicked();
        hovered = false;
    }
}

SDL_Rect Button::getPosition() { return _position; }

void Button::setPosition(SDL_Rect pos) { _position = pos; }
