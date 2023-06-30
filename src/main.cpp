
#include "Gameplay.h"

int main() {
    Gameplay g;
    g.start();

    while (g.isGameOn()) {
        g.update();
    }

    g.end();

    return 0;
}
