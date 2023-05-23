#include "Gameplay.h"
#include "Dice.h"
#include "Window.h"
#include <SDL2/SDL.h>
#include <cstdio>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>

Gameplay::Gameplay() {}

void Gameplay::start() {
  d20 = Dice(20);
  gameOn = true;
  mainWindow.start();
}

bool Gameplay::isGameOn() { return gameOn; }

void Gameplay::end() {
  gameOn = false;
  mainWindow.end();
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
      break;
    }
  }
}
