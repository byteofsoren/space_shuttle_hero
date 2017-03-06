#include <iostream>
#include "Game.hpp"
#include "Graphics.hpp"
#include "Actor.hpp"
#include "Player.hpp"

#include <unistd.h>

Game::Game() : renderer(800, 800, "Space Shuttle Hero") {
    // Reset everything here
}

Game::~Game() {

}

int Game::init() {
    actors.push_back(new Player{1,1});
    actors.back()->setPos(100, 100);
    renderer.addTile(actors.back()->getTile());

    actors.push_back(new Player{0,1});
    actors.back()->setPos(300, 100);
    renderer.addTile(actors.back()->getTile());

    return 1;
}

int Game::run() {
    while (renderer.tryUpdate())
    {
        for (unsigned i = 0; i < this->actors.size(); i++) {
            this->actors[i]->update();
        }
    }
    
    return 1;
}
