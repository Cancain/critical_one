#include "Gameplay.h"

#include "Button.h"
#include "Dice.h"
#include "Window.h"
#include "functional"

Gameplay::Gameplay() { _mainWindow.start(); }

void Gameplay::_renderRollButton() {
    SDL_Surface *buttonNormalSurface = SDL_LoadBMP("assets/button_normal.bmp");
    SDL_Surface *buttonHoverSurface = SDL_LoadBMP("assets/button_hovered.bmp");
    SDL_Surface *buttonClickedSurface = SDL_LoadBMP("assets/button_clicked.bmp");
    button = new Button(_mainWindow.getRenderer(), buttonNormalSurface, buttonClickedSurface,
                        buttonHoverSurface);
    // button = new Button(_mainWindow.getRenderer(), buttonNormalSurface);
    button->renderButton(_mainWindow.getSurface());
}

void Gameplay::start() {
    _renderRollButton();
    _d20 = Dice(20);
    _gameOn = true;
}

bool Gameplay::isGameOn() { return _gameOn; }

void Gameplay::end() {
    _gameOn = false;
    _mainWindow.end();
    SDL_Quit();
    delete button;
}

void Gameplay::update() {
    _mainWindow.update();

    SDL_Event e;
    if (SDL_PollEvent(&e) != 0) {
        handleInput(e);
    }
}

void Gameplay::_rolld20() {
    int roll = _d20.roll();
    char message[50];
    sprintf(message, "You rolled %i\n", roll);
    char *text = message;
    _mainWindow.printText(text);
}

void Gameplay::handleInput(SDL_Event event) {
    if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEMOTION) {
        button->update(event, [this]() {
            _mainWindow.printText("Clicked!");
            _rolld20();
            _renderRollButton();
        });
    }

    if (event.type == SDL_KEYDOWN) {
        auto key = event.key.keysym.sym;

        switch (key) {
            case SDLK_ESCAPE:
                end();
                break;
        }
    }
}
