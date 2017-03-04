#include <iostream>
#include "Game.hpp"

Game::Game() : renderer(800, 800, "Space Shuttle Hero") {
    // Reset everything here

    p1.setXPos = 
}

Game::~Game() {

}

int Game::init() {
    this->obj1.posX = 20.0;
    this->obj1.posY = 20.0;
    this->obj2.posX = 300.0;
    this->obj2.posY = 300.0;

    this->renderer.addTile(this->obj1);
    this->renderer.addTile(this->obj2);
        
    return 1;
}

int Game::run() {
    this->renderer.update();
    
    std::cout << "Hello World!" << std::endl;
        
    return 0;
}
