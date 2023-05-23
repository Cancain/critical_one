#include "Gameplay.h"
#include "Dice.h"
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

void Gameplay::handleInput(std::basic_istream<char>::int_type input) {
  if (input == 'q') {
    end();
  }
  if (input == 'c') {
  }
  if (input == 'r') {
    std::printf("You rolled %i\n", d20.roll());
  }
}

int Gameplay::rollD20() {
  int roll = d20.roll();
  printf("you rolled: %d\n", roll);
  return roll;
}
