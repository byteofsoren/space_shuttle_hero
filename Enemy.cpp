// enemies.cpp
#include <iostream>
#include <typeinfo>
#include "Enemy.hpp"

// Public
Enemy::Enemy() {
    this->life = 1;
    this->damage = 1;
    this->collisionRadius = 25;
    this->tile.source = "enemy.png";
}
	
Enemy::Enemy(int life, int damage) {
    this->life = life;
    this->damage = damage;
}
	
Enemy::~Enemy() {
    
}

void Enemy::act(Actor &a) {
    if (a.getType() == Actor::player && a.getInvincible() <= 0) {
        if (a.getLife() > 0) {
            a.setLife(a.getLife()-1);
            a.setInvincible(100);
            a.setXPos(400);
            a.setYPos(600);
        } else {
            a.setXPos(1000);
            a.setYPos(1000);
        }
        //std::cout << "crash!" << std::endl;
    }
    
    //std::cout << "testing" << std::endl;
    
    return;
}
