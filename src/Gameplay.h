#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "Dice.h"
#include <iostream>
#include <istream>

class Gameplay {
public:
  void start();
  void end();
  bool isGameOn();
  void handleInput(std::basic_istream<char>::int_type input);
  Dice d20;

private:
  bool gameOn = false;
};

#endif
