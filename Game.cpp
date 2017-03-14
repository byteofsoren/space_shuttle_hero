#include <iostream>
#include <cmath>
#include "Game.hpp"
#include "Graphics.hpp"
#include "Actor.hpp"
#include "Player.hpp"
#include "Projectile.hpp"

#include <unistd.h>

Game::Game() : renderer(800, 800, "Space Shuttle Hero") {
    // Reset everything here
    this->p1 = 0;
    this->p2 = 0;
}

Game::~Game() {
    for (auto a : this->actors) { // Delete all actors
        if (a->getType() != Actor::projectile) {
            delete a;
        }
    }

    delete[] projectiles;
    delete hud1;
    delete hud2;
}

int Game::init() {
    actors.push_back(new Player{0,3});
    p1 = (Player*)actors.back();
    p1->setCR(25);
    //p1->setTexture("uglySpaceship.png");

    actors.push_back(new Player{1,3});
    p2 = (Player*)actors.back();
    p2->setCR(25);

    this->p1->setPos(200, 600);
    this->p2->setPos(600, 600);

    // === The huds for the player is initialized here ===
    int hudypos = 700;
    this->hud1 = new Hud(50,hudypos);
    this->hud2 = new Hud(50*7, hudypos);
    this->hud1->conectActor(*p1);
    this->hud2->conectActor(*p2);
    renderer.addTile(this->hud1->getTile());
    renderer.addTile(this->hud2->getTile());
    renderer.addTile(this->hud1->getTextTile());
    renderer.addTile(this->hud2->getTextTile());

    // === End hud init ==
    

    /* Initialise formations */
    
    formations.push_back(Formation(5,0));
    formations.push_back(Formation(5,1));
    formations.push_back(Formation(3,2));
    
    for (auto &form : formations) {
        for (auto &enemy : form.getEnemies()) {
            this->actors.push_back(enemy);
        }
    }

    this->spawns.push(SpawnPoint(1500, (Formation*)&formations[0], 2));
    this->spawns.push(SpawnPoint(5000, (Formation*)&formations[1], 1));
    this->spawns.push(SpawnPoint(10000, (Formation*)&formations[2], 0));
    this->spawns.push(SpawnPoint(20000, (Formation*)&formations[1], 2));
    this->spawns.push(SpawnPoint(25000, (Formation*)&formations[0], 0));
    this->spawns.push(SpawnPoint(0,0,0));

    projectiles = new Projectile[200];

    for (int i=0; i < 200; i++) {
        this->actors.push_back(&projectiles[i]);
    }
    
    for (auto &a : this->actors) {
        renderer.addTile(a->getTile());
    }

    
    this->goal = sf::seconds(30);

    this->gameClock.restart();
    
    return 1;
}

int Game::run() {
    SpawnPoint p = this->spawns.front();
    int currentShot = 0;
    bool game_over = false;
    
    std::cout << p.time.asMilliseconds() << " " << p.type << " " << this->goal.asSeconds() << " " << this->gameClock.getElapsedTime().asSeconds() << std::endl;
    
    while (renderer.tryUpdate() && !game_over)
    {
        // Spawn any formations
        
        if (p.formation != 0 && p.time < this->gameClock.getElapsedTime()) {
            p.formation->spawn(p.type);
            this->spawns.pop();
            p = this->spawns.front();
        } 
        
        for (auto &form : formations) {
            form.update();
        }
            
        // Check collisions and run act() on relevant actors

        for (auto i : this->actors) {
            if (i->isAlive()) {
                // Check collisions with everything
                for (auto j : this->actors) {
                    if (j->getXPos() > -1 && j->getXPos() < 801 &&
                        j->getYPos() > -1 && j->getYPos() < 801 &&
                        i != j && i->collidesWith(j)) {
                        i->act(*j);
                    }
                }
            } else {
                // Move actors outside screen
                i->setXPos(-100);
                i->setYPos(-100);
            }
        }

        // Update actors

        for (auto &a : this->actors) {
            a->update();
        }

        // Shoot projectiles with P1
        
        if (p1->isShooting(this->gameClock.getElapsedTime())) {
            this->projectiles[currentShot].setXPos(p1->getXPos());
            this->projectiles[currentShot].setYPos(p1->getYPos()-10);
            this->projectiles[currentShot].setLife(1);
            currentShot = (currentShot+1)%200;
        }

        // Shoot projectiles with P2
        
        if (p2->isShooting(this->gameClock.getElapsedTime())) {
            this->projectiles[currentShot].setXPos(p2->getXPos());
            this->projectiles[currentShot].setYPos(p2->getYPos()-10);
            this->projectiles[currentShot].setLife(1);
            currentShot = (currentShot+1)%200;
        }

        // Update HUD

        this->hud1->update();
        this->hud2->update();

        // Check victory conditions and finish
        if (this->goal < this->gameClock.getElapsedTime()) {
            std::cout << "You win!" << std::endl;
            game_over = true;
        } else if (this->p1->getLife() <= 0 && this->p2->getLife() <= 0) {
            std::cout << "You lose!" << std::endl;
            game_over = true;
        }
        
        // Be nice to the rest of the programs on the computer, as well as the CPU

        sf::sleep(sf::milliseconds(10));
    }
    
    return 1;
}
