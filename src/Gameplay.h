#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "Dice.h"
#include "Window.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <istream>

class Gameplay {
public:
  Gameplay();
  void start();
  void end();
  bool isGameOn();
  void handleInput(SDL_Event event);

private:
  Window mainWindow;
  Dice d20 = Dice(20);
  bool gameOn = false;
};

#endif
