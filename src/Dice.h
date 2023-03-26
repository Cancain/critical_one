#ifndef DICE_H
#define DICE_H

class Dice {
public:
  Dice(int maxVal);
  void roll();
  int getValue();

private:
  int currentValue = 0;
  int maxValue = 0;
};

#endif
