#include <iostream>
#include <cmath>
#include "Game.hpp"
#include "Graphics.hpp"
#include "Actor.hpp"
#include "Player.hpp"

#include <unistd.h>

Game::Game() : renderer(800, 800, "Space Shuttle Hero") {
    // Reset everything here
    this->p1 = 0;
    this->p2 = 0;
}

Game::~Game() {

}

int Game::init() {
    actors.push_back(new Player{0,5});
    this->p1 = (Player*)actors.back();
    renderer.addTile(actors.back()->getTile());

    actors.push_back(new Player{1,3});
    this->p2 = (Player*)actors.back();
    renderer.addTile(actors.back()->getTile());

    this->p1->setPos(100, 100);
    this->p2->setPos(300, 100);

    this->p1Life.posY = 30;
    this->p1Life.posX = 30;
    this->p1Life.height = 20;
    this->p1Life.identifier = "p1Life";

    this->p2Life.posY = 30;
    this->p2Life.height = 20;
    this->p2Life.identifier = "p2Life";

    renderer.addTile(&this->p1Life);
    renderer.addTile(&this->p2Life);
    
    return 1;
}

int Game::run() {    
    while (renderer.tryUpdate())
    {
        // Update actors

        for (unsigned i = 0; i < this->actors.size(); i++) {
            this->actors[i]->update();
        }

        // Check collisions and run act() on relevant actors

        for (unsigned i = 0; i < this->actors.size(); i++) {
            for (unsigned j = 0; j < this->actors.size(); j++) {
                int dx = this->actors[i]->getXPos() - this->actors[j]->getXPos();
                int dy = this->actors[i]->getYPos() - this->actors[j]->getYPos();

                if (this->actors[i]->getCR() + this->actors[j]->getCR() > std::hypot(dx, dy)) {
                    // Collision detected, act on it
                    this->actors[i]->act(*this->actors[j]);
                }
            }
        }

        // Update GUI

        this->p1Life.width = 20*this->p1->getLife();
        this->p2Life.width = 20*this->p2->getLife();
        this->p2Life.posX = 770 - this->p2Life.width;

        // Be nice to the rest of the programs on the computer, as well as the CPU
        
        sf::sleep(sf::milliseconds(10));
    }
    
    return 1;
}
