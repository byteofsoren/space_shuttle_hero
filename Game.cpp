#include <iostream>
#include "Game.hpp"
#include "Graphics.hpp"
#include "Actor.hpp"

Game::Game() : renderer(800, 800, "Space Shuttle Hero") {
    // Reset everything here

}

Game::~Game() {

}

int Game::init() {
    Tile_t e1 = {10, 10, 20, 20, ""};
    std::vector<Actor> Actors;

    Actors.push_back(Actor());
    Actors.back().setXPos(10);
    Actors.back().setYPos(10);
    Actors.back().setXVel(1);
    Actors.back().setYVel(1);

    Actors.push_back(Actor());
    Actors.back().setXPos(220);
    Actors.back().setYPos(100);
    Actors.back().setXVel(1);
    Actors.back().setYVel(1);

    this->renderer.addTile(this->obj1);
    this->renderer.addTile(this->obj2);
    return 1;
}

int Game::run() {
    this->renderer.update();
    this->renderer.run();
    while (this->renderer.isOpen()) {}
    std::cout << "Hello World!" << std::endl;

    return 0;
}
