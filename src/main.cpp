
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

  // Hack to get window to stay up
  SDL_Event e;
  while (g.isGameOn()) {
    while (SDL_PollEvent(&e) != 0) {
      g.handleInput(e);
    }
  }

  return 0;
}
