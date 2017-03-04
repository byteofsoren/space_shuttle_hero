#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include "Graphics.hpp"
#include "Actor.hpp"
#include <iostream>
#include <unistd.h>


int main(/*int argc, char** argv*/) {
    //testGraphics();
    //return 0;
    Game* g = new Game();
    int res;
    if ((res = g->init())) {
        res = g->run();
    }
    sleep(10);
    res = (res > 0) ? 0 : -1;            // If res is zero, something went wrong
    delete g;
    return res;

}
