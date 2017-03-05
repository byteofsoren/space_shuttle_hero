#include <iostream>
#include "Game.hpp"
#include "Graphics.hpp"
#include "Actor.hpp"

#include <unistd.h>

Game::Game() : renderer(800, 800, "Space Shuttle Hero") {
    // Reset everything here

}

Game::~Game() {

}

int Game::init() {
    actors.push_back({});
    actors.back().setPos(100, 100);
    actors.back().setXVel(100);
    renderer.addTile(actors.back().getTile());

    return 1;
}

int Game::run() {
    while (renderer.tryUpdate())
    {
        actors.back().update();
    }
    return 1;
}
