#include "Game.hpp"
#include "Graphics.hpp"

void testGraphics()
{
    Graphics window(800,600,"Game on");
    struct Tile_t rect = {
        .posX = 200;
    };
}

int main(int argc, char** argv) {
    Game g;

    if (g.init()) {
        return g.run();
    }

    return 0;
}
