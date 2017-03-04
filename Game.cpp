#include <iostream>
#include "Game.hpp"
#include "Graphics.hpp"

Game::Game() : renderer(800, 800, "Space Shuttle Hero") {
    // Fix renderers here
}

Game::~Game() {

}

int Game::init() {
    Tile_t e1 = {10, 10, 20, 20, ""}
    std::vector<Actor> Actors;
    Actors.push_back({});

    this->renderer.addTile(this->obj1);
    this->renderer.addTile(this->obj2);
        
    return 1;
}

int Game::run() {
    this->renderer.update();
    
    std::cout << "Hello World!" << std::endl;
        
    return 0;
}
