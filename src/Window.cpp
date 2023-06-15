#include "Window.h"

#include <SDL2/SDL_ttf.h>

#include <filesystem>
#include <iostream>

#include "Button.h"
#include "Constants.h"

Window::Window() {
    printf("Window constructor\n");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        if (TTF_Init() < 0) {
            printf("SDL_TTF could not initialize! SDL_Error: %s\n", TTF_GetError());
        }
        window = SDL_CreateWindow("Critical one", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                  WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            return;
        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

            windowSurface = SDL_GetWindowSurface(window);
            SDL_UpdateWindowSurface(window);
        }
    }
}

void Window::update() {
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return;
    } else {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        windowSurface = SDL_GetWindowSurface(window);
        SDL_UpdateWindowSurface(window);
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
    SDL_BlitSurface(textSurface, NULL, windowSurface, NULL);

    SDL_UpdateWindowSurface(window);
    SDL_FreeSurface(textSurface);
}

void Window::clearWindow() {
    SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 0xFF, 0xFF, 0xFF));

    SDL_UpdateWindowSurface(window);
}

void Window::renderButton() {
    SDL_Surface *buttonNormalSurface = SDL_LoadBMP("assets/button_normal.bmp");
    SDL_Surface *buttonHoverSurface = SDL_LoadBMP("assets/button_hovered.bmp");
    SDL_Surface *buttonClickedSurface = SDL_LoadBMP("assets/button_clicked.bmp");

    Button button = Button(renderer, buttonNormalSurface);
    button.renderButton(windowSurface);

    SDL_UpdateWindowSurface(window);
};

void Window::start() {
    clearWindow();
    renderButton();
};

void Window::end() {
    SDL_DestroyWindow(window);
    SDL_Quit();
};