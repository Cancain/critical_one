#include "Gameplay.h"
#include "Dice.h"
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
}

bool Gameplay::isGameOn() { return gameOn; }

void Gameplay::end() { gameOn = false; }

void Gameplay::handleInput(SDL_Event event) {
  auto key = event.key.keysym.sym;

  switch (key) {
  case SDLK_ESCAPE:
    end();
    break;

  case SDLK_r:
    std::printf("You rolled %i\n", d20.roll());
    break;

  default:
    break;
  }
}
