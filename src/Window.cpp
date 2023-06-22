#include "Window.h"

#include <SDL2/SDL_ttf.h>

#include <filesystem>
#include <iostream>

#include "Constants.h"

Window::Window() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        if (TTF_Init() < 0) {
            printf("SDL_TTF could not initialize! SDL_Error: %s\n", TTF_GetError());
        }
        _window = SDL_CreateWindow("Critical one", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                   WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
        if (_window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            return;
        } else {
            _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

            _windowSurface = SDL_GetWindowSurface(_window);
            SDL_UpdateWindowSurface(_window);
        }
    }
}

void Window::update() {
    if (_window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return;
    } else {
        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

        _windowSurface = SDL_GetWindowSurface(_window);
        SDL_UpdateWindowSurface(_window);
    }
}

void Window::printText(char *text) {
    clearWindow();
    const char *fontPath = "assets/font.ttf";
    int fontSize = 24;
    TTF_Font *font = TTF_OpenFont(fontPath, fontSize);

    if (!font) {
        printf("Failed to load font: %s\n", TTF_GetError());
    }

    SDL_Color textColor = {0, 0, 0};
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, textColor);

    if (!textSurface) {
        printf("Failed to render text: %s\n", TTF_GetError());
    }
    SDL_BlitSurface(textSurface, NULL, _windowSurface, NULL);

    SDL_UpdateWindowSurface(_window);
    SDL_FreeSurface(textSurface);
}

void Window::clearWindow() {
    SDL_FillRect(_windowSurface, NULL, SDL_MapRGB(_windowSurface->format, 0xFF, 0xFF, 0xFF));

    SDL_UpdateWindowSurface(_window);
}

void Window::start() { clearWindow(); };

void Window::end() {
    SDL_DestroyWindow(_window);
    SDL_Quit();
};

SDL_Renderer *Window::getRenderer() { return _renderer; }

SDL_Surface *Window::getSurface() { return _windowSurface; }