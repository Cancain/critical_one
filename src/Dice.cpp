#include "Dice.h"
#include <cstdlib>

Dice::Dice(int maxVal) { maxValue = maxVal; }

void Dice::roll() { currentValue = 10; }

int Dice::getValue() { return currentValue; }
