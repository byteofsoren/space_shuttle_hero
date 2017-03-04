#include <iostream>
#include "game.hpp"

Game::Game() {

}

Game::~Game() {

}

int Game::init() {
    return 1;
}

int Game::run() {
    std::cout << "Hello World!" << std::endl;
        
    return 0;
}
