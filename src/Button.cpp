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
    _windowSurface = windowSurface;

    if (!_normalSurface) {
        printf("Failed to load normal button surface: %s\n", SDL_GetError());
    }

    if (_clickedSurface != NULL) {
        _buttonClickedTexture = SDL_CreateTextureFromSurface(_renderer, _clickedSurface);
    }

    if (_hoveredSurface != NULL) {
        _buttonHoveredTexture = SDL_CreateTextureFromSurface(_renderer, _hoveredSurface);
    }

    _buttonNormalTexture = SDL_CreateTextureFromSurface(_renderer, _normalSurface);

    SDL_BlitSurface(_normalSurface, NULL, windowSurface, &_position);
};

void Button::onClick() { printf("Button clicked!"); }

bool buttonHovered = false;

void Button::update(SDL_Event &e, const std::function<void()> &clicked) {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    SDL_Rect pos = {x : (800 / 2) - buttonRect.w / 2, y : (600 / 2) - buttonRect.h};

    bool isWithin = mouseX >= _position.x && mouseX <= _position.x + buttonRect.w &&
                    mouseY >= _position.y && mouseY <= _position.y + buttonRect.h;

    if (isWithin && _windowSurface && !buttonHovered && _hoveredSurface) {
        printf("hovered\n");
        SDL_BlitSurface(_hoveredSurface, NULL, _windowSurface, &_position);
        buttonHovered = true;
    }

    if (!isWithin && _windowSurface && buttonHovered && _normalSurface) {
        printf("unhovered\n");
        SDL_BlitSurface(_normalSurface, NULL, _windowSurface, &_position);
        buttonHovered = false;
    }

    if (e.button.button == SDL_BUTTON_LEFT && isWithin) {
        clicked();
        buttonHovered = false;

        Uint32 startTime = SDL_GetTicks();
        Uint32 currentTime = startTime;
        const Uint32 delayTime = 100;

        while (currentTime - startTime < delayTime) {
            SDL_BlitSurface(_clickedSurface, NULL, _windowSurface, &_position);
            currentTime = SDL_GetTicks();
        }
        SDL_BlitSurface(_hoveredSurface, NULL, _windowSurface, &_position);
    }
}

void Button::end() {
    SDL_FreeSurface(_normalSurface);

    if (_buttonNormalTexture) {
        SDL_DestroyTexture(_buttonNormalTexture);
    }

    if (_clickedSurface != NULL) {
        SDL_FreeSurface(_clickedSurface);
        SDL_DestroyTexture(_buttonClickedTexture);
    }

    if (_hoveredSurface != NULL) {
        SDL_FreeSurface(_hoveredSurface);
        SDL_DestroyTexture(_buttonHoveredTexture);
    }
}

SDL_Rect Button::getPosition() { return _position; }

void Button::setPosition(SDL_Rect pos) { _position = pos; }
