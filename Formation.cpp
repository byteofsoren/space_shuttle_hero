#include "Formation.hpp"
#include "Actor.hpp"

Formation::Formation() {
    this->end = sf::seconds(10);
}

Formation::Formation(int size, int enemyType) : Formation() {
    for (int i=0; i < size; i++) {
        this->enemies.push_back(new Actor());
    }
}

Formation::~Formation() { }

void Formation::spawn(int type) {
    this->clock.restart();
    this->type = type;
}

void Formation::update() {
    int t = this->clock.getElapsedTime().asMilliseconds() / 10;
    double x;

    if (t < this->end.asMilliseconds()) {
    }
    
    for (unsigned i = 0; i < this->enemies.size(); i++) {        
        switch (this->type) {
            case 0:
                x = t - i*75;
                this->enemies[i]->setXPos(x);
                this->enemies[i]->setYPos(x);
                break;
            case 1:
                x = t - i*25;
                this->enemies[i]->setXPos(x);
                this->enemies[i]->setYPos(0.0005*((x-400)*(x-50)*(x+200)) + 400);
                break;
        }
    }
}
