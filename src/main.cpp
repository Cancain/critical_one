
#include "Gameplay.h"
#include "Window.h"
#include <SDL2/SDL.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>

int main() {
  Gameplay g;
  g.start();

  SDL_Event e;
  while (g.isGameOn()) {
    if (SDL_PollEvent(&e) != 0) {
      g.handleInput(e);
    }
  }

  return 0;
}
