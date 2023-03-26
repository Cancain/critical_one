#include "Dice.h"
#include <SDL2/SDL.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>

int main() {
  Dice d(20);
  d.roll();

  std::printf("%d", d.getValue());
  return 0;
}
