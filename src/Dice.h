#ifndef DICE_H
#define DICE_H

class Dice {
   public:
    Dice();
    Dice(int maxVal);
    int roll();

   private:
    int _maxValue = 0;
};

#endif
