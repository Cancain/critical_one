#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <SDL2/SDL.h>

#include "Button.h"
#include "Dice.h"
#include "Window.h"

class Gameplay {
   public:
    Gameplay();
    void start();
    void end();
    bool isGameOn();
    void handleInput(SDL_Event event);
    void update();
    Button *button = nullptr;

   private:
    void _renderRollButton();
    void _rolld20();
    Window _mainWindow;
    Dice _d20 = Dice(20);
    bool _gameOn = false;
};

#endif
