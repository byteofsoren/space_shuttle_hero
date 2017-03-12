// enemies.cpp
#include <iostream>
#include <typeinfo>
#include "Enemy.hpp"

// Public
Enemy::Enemy() {
    this->life = 1;
    this->damage = 1;
    this->collisionRadius = 25;
}
	
Enemy::Enemy(int life, int damage) {
    this->life = life;
    this->damage = damage;
}
	
Enemy::~Enemy() {
    
}

void Enemy::act(Actor &a) {
    if (a.getType() == Actor::player) {
        std::cout << "crash!" << std::endl;
    }
    
    //std::cout << "testing" << std::endl;
    
    return;
}
