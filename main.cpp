#include "game.hpp"

int main(int argc, char** argv) {
    Game g;

    if (g.init()) {
        return g.run();
    }

    return 0;
}
