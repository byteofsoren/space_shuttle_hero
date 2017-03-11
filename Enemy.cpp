// enemies.cpp
#include <iostream>
#include "Enemy.hpp"

// Public
Enemy::Enemy() {
    this->life = 0;
    this->damage = 0;
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
    return;
}
	
void Enemy::act(Actor &a) {
    return;
}
