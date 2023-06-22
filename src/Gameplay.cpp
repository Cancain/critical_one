#include "Gameplay.h"

#include <SDL2/SDL.h>

#include <cstdio>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>

#include "Button.h"
#include "Dice.h"
#include "Window.h"

Gameplay::Gameplay() { mainWindow.start(); }

void Gameplay::start() {
    SDL_Surface *buttonNormalSurface = SDL_LoadBMP("assets/button_normal.bmp");
    // SDL_Surface *buttonHoverSurface = SDL_LoadBMP("assets/button_hovered.bmp");
    // SDL_Surface *buttonClickedSurface = SDL_LoadBMP("assets/button_clicked.bmp");
    button = new Button(mainWindow.getRenderer(), buttonNormalSurface);
    button->renderButton(mainWindow.getSurface());
    d20 = Dice(20);
    gameOn = true;
}

bool Gameplay::isGameOn() { return gameOn; }

void Gameplay::end() {
    gameOn = false;
    mainWindow.end();
    SDL_Quit();
}

void Gameplay::update() {
    mainWindow.update();

    SDL_Event e;
    if (SDL_PollEvent(&e) != 0) {
        handleInput(e);
        if (button != nullptr) {
            button->update(e);
        }
    }
}

void Gameplay::handleInput(SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        auto key = event.key.keysym.sym;

        switch (key) {
            case SDLK_ESCAPE:
                end();
                break;

            case SDLK_r: {
                int roll = d20.roll();
                char message[50];
                sprintf(message, "You rolled %i\n", roll);
                char *text = message;
                mainWindow.printText(text);
                break;
            }

            default:
                return;
                break;
        }
    }
}
