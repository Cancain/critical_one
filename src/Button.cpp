#include "Button.h"

#include <iostream>

Button::Button(Window *window, SDL_Rect pos, SDL_Surface *normalSurface,
               SDL_Surface *clickedSurface, SDL_Surface *hoveredSurface)
    : Button(window, pos, normalSurface, clickedSurface) {
    _hoveredSurface = hoveredSurface;
}

Button::Button(Window *window, SDL_Rect pos, SDL_Surface *normalSurface,
               SDL_Surface *clickedSurface)
    : Button(window, pos, normalSurface) {
    _clickedSurface = clickedSurface;
}

Button::Button(Window *window, SDL_Rect pos, SDL_Surface *normalSurface) {
    _position = pos;
    _mainWindow = window;
    _renderer = window->getRenderer();
    _normalSurface = normalSurface;
    buttonRect.w = _normalSurface->w;
    buttonRect.h = _normalSurface->h;
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

bool Button::_isCursorWithin() {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    return mouseX >= _position.x && mouseX <= _position.x + buttonRect.w && mouseY >= _position.y &&
           mouseY <= _position.y + buttonRect.h;
}

void Button::_manageHover(SDL_Event &e) {
    if (e.type == SDL_MOUSEMOTION) {
        if (_isCursorWithin() && _windowSurface && !_buttonHovered && _hoveredSurface) {
            SDL_BlitSurface(_hoveredSurface, NULL, _windowSurface, &_position);
            _buttonHovered = true;
        }

        if (!_isCursorWithin() && _windowSurface && _buttonHovered && _normalSurface) {
            SDL_BlitSurface(_normalSurface, NULL, _windowSurface, &_position);
            _buttonHovered = false;
        }
    }
}

bool Button::_isClicked(SDL_Event &e) { return e.type == SDL_MOUSEBUTTONDOWN && _isCursorWithin(); }

void Button::update(SDL_Event &e, const std::function<void()> &clicked) {
    if (_isClicked(e)) {
        clicked();
    }
    _manageHover(e);
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
