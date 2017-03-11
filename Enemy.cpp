// enemies.cpp
#include <iostream>
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
	
void Enemy::act(Player &a){
    //this->life = 0;
    a.life -= this->damage;
    std::cout << "Life: " << a.life << std::endl;
    return;
}

	
void Enemy::act(Actor &a) {
    //std::cout << "testing" << std::endl;
    
    return;
}
