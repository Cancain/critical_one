#include "Dice.h"

#include <cstddef>
#include <cstdlib>
#include <ctime>

Dice::Dice() {}

Dice::Dice(int maxVal) {
    srand(time(NULL));
    _maxValue = maxVal;
}

int Dice::roll() { return rand() % _maxValue + 1; }
