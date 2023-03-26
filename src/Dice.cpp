#include "Dice.h"
#include <cstddef>
#include <cstdlib>
#include <ctime>

Dice::Dice(int maxVal) {
  srand(time(NULL));
  maxValue = maxVal;
}

int Dice::roll() { return rand() % maxValue + 1; }
