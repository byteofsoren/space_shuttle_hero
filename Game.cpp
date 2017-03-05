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
    actors.push_back({});
    actors.back().setPos(100, 100);
    renderer.addTile(actors.back().getTile());

    return 1;
}

int Game::run() {
    this->renderer.startThreads();
    while (this->renderer.isOpen()) {}
    std::cout << "Hello World!" << std::endl;

    return 1;
}
