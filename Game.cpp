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
    std::vector<Actor*> actors;
    Actor player1;
    player1.setPos(10,100);
    Actor player2;
    player2.setPos(40,130);
    renderer.addTile(player1.getTile());
    renderer.addTile(player2.getTile());

    return 1;
}

int Game::run() {
    this->renderer.startThreads();
    while (this->renderer.isOpen()) {}
    std::cout << "Hello World!" << std::endl;

    return 0;
}
