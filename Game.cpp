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
    delete form;
}

int Game::init() {
    players.push_back(new Player{0,5});
    p1 = (Player*)players.back();
    p1->setCR(25);
    p1->setTexture("uglySpaceship.png");
    renderer.addTile(p1->getTile());

    players.push_back(new Player{1,3});
    p2 = (Player*)players.back();
    p2->setCR(25);
    renderer.addTile(p2->getTile());

    this->p1->setPos(300, 200);
    this->p2->setPos(300, 100);

    this->p1Life.posY = 30;
    this->p1Life.posX = 30;
    this->p1Life.source = "health.png";

    this->p2Life.posX = 600;
    this->p2Life.posY = 300;
    this->p2Life.source = "health.png";

    renderer.addTile(&this->p1Life);
    renderer.addTile(&this->p2Life);

    form = new Formation(5,0);

    for (auto &enemy : form->getEnemies()) {
        this->actors.push_back(enemy);
        renderer.addTile(enemy->getTile());
    }
    form->spawn(2);
    return 1;
}

int Game::run() {
    while (renderer.tryUpdate())
    {
        // Check collisions and run act() on relevant actors

        this->form->update();

        for (unsigned i = 0; i < this->actors.size(); i++) {
            if (!actors[i]->isAlive()) {
                //Ta bort actor från vektor och avregistrera.
            }
            else {
                for (unsigned j = 0; j < this->actors.size(); j++) {
                    if (i != j && actors[i]->collidesWith(actors[j])) {
                        //std::cout << "Crash!" << std::endl;
                    }
                }
                for (size_t j = 0; j < this->players.size(); j++) {
                    if (players[j]->collidesWith(actors[i])) {
                        //
                    }
                }
            }
        }

        // Update actors

        for (unsigned i = 0; i < this->actors.size(); i++) {
            this->actors[i]->update();
        }

        for (unsigned i = 0; i < this->players.size(); i++) {
            this->players[i]->update();
            if (players[i]->isShooting()) {
                // Generate misile.
            }
        }

        // Update GUI

        /*this->p1Life.width = 20*this->p1->getLife();
        this->p2Life.width = 20*this->p2->getLife();
        this->p2Life.posX = 770 - this->p2Life.width;*/

        // Be nice to the rest of the programs on the computer, as well as the CPU
        
        sf::sleep(sf::milliseconds(10));
    }
    
    return 1;
}
