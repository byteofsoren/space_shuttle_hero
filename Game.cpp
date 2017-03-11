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

    // === The huds for the player is initialized here ===
    int hudxpos = 500;
    this->hud1 = new Hud(50,hudxpos);
    this->hud2 = new Hud(50*7, hudxpos);
    this->hud1->conectActor(*p1);
    this->hud2->conectActor(*p2);
    renderer.addTile(this->hud1->getTile());
    renderer.addTile(this->hud2->getTile());
    renderer.addTile(this->hud1->getTextTile());
    renderer.addTile(this->hud2->getTextTile());

    // === End intit ==


    /* Initialise formations */
    
    formations.push_back(Formation(5,0));
    formations.push_back(Formation(5,1));
    formations.push_back(Formation(3,2));
    
    for (auto form : formations) {
        for (auto &enemy : form.getEnemies()) {
            this->actors.push_back(enemy);
            renderer.addTile(enemy->getTile());
        }
    }

    this->spawns.push(SpawnPoint(1500, (Formation*)&formations[0], 2));
    this->spawns.push(SpawnPoint(5000, (Formation*)&formations[1], 1));
    this->spawns.push(SpawnPoint(10000, (Formation*)&formations[2], 0));
    this->spawns.push(SpawnPoint(20000, (Formation*)&formations[1], 2));
    this->spawns.push(SpawnPoint(25000, (Formation*)&formations[0], 0));
    this->spawns.push(SpawnPoint(0,0,0));

    this->goal = sf::seconds(30);
    
    this->gameClock.restart();
    
    return 1;
}

int Game::run() {
    SpawnPoint p = this->spawns.front();
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
        
        for (auto form : formations) {
            form.update();
        }
            
        // Check collisions and run act() on relevant actors

        for (unsigned i = 0; i < this->actors.size(); i++) {
            if (!actors[i]->isAlive()) {
                //Ta bort actor från vektor och avregistrera.
            }
            else {
                for (unsigned j = 0; j < this->actors.size(); j++) {
                    if (i != j && actors[i]->collidesWith(actors[j])) {
                        actors[i]->act(*actors[j]);
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
