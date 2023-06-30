#include "Gameplay.h"

#include "Button.h"
#include "Constants.h"
#include "Dice.h"
#include "Window.h"
#include "functional"

Gameplay::Gameplay() { _mainWindow.start(); }

void Gameplay::_renderRollButton() {
    SDL_Surface *buttonNormalSurface = SDL_LoadBMP("assets/button_normal.bmp");
    SDL_Surface *buttonHoverSurface = SDL_LoadBMP("assets/button_hovered.bmp");
    SDL_Surface *buttonClickedSurface = SDL_LoadBMP("assets/button_clicked.bmp");
    button =
        new Button(&_mainWindow, buttonNormalSurface, buttonClickedSurface, buttonHoverSurface);
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
    button->end();
    delete button;
    SDL_Quit();
}

void Gameplay::update() {
    _waitForTargetFramerate();
    _updateDeltaTime();
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
    button->update(event, [this]() {
        _mainWindow.printText("Clicked!");
        _rolld20();
        _renderRollButton();
    });

    if (event.type == SDL_KEYDOWN) {
        auto key = event.key.keysym.sym;

        switch (key) {
            case SDLK_ESCAPE:
                end();
                break;
        }
    }
}

void Gameplay::SetDeltatime(float deltaTime) { _deltaTime = deltaTime; }

float Gameplay::getDeltaTime() { return _deltaTime; }

void Gameplay::_updateDeltaTime() {
    _deltaTime = (SDL_GetTicks() - _ticksLastFrame) / 1000.0f;
    _ticksLastFrame = SDL_GetTicks();
    _deltaTime = _deltaTime > 0.05f ? 0.05f : _deltaTime;
}

void Gameplay::_waitForTargetFramerate() {
    int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - _ticksLastFrame);

    if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME) {
        SDL_Delay(timeToWait);
    }
}
