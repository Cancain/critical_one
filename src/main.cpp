
#include "Gameplay.h"

int main() {
    Gameplay g;
    g.start();

    while (g.isGameOn()) {
        g.update();
    }

    return 0;
}
