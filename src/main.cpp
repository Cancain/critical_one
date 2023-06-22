
#include <SDL2/SDL.h>

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>

#include "Gameplay.h"

int main() {
    Gameplay g;
    g.start();

    while (g.isGameOn()) {
        g.update();
    }

    return 0;
}
