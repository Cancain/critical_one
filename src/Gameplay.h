#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "Dice.h"
#include <iostream>
#include <istream>

class Gameplay {
public:
  Gameplay();
  void start();
  void end();
  bool isGameOn();
  void handleInput(std::basic_istream<char>::int_type input);
  int rollD20();

private:
  Dice d20 = Dice(20);
  bool gameOn = false;
};

#endif
