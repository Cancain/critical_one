// #include "Dice.h"
// #include "Gameplay.h"
#include "Gameplay.h"
#include <SDL2/SDL.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>

int main() {
  std::cout << "hey";

  Gameplay g;
  g.start();

  while (g.isGameOn()) {
    char input;
    std::cin >> input;

    g.handleInput(input);
    if (input == 'q') {
      g.end();
    }
  }
  return 0;
}
