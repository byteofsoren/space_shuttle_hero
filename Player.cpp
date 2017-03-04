// player.cpp
#include <iostream>
#include "Player.hpp"

// Public
	Player::Player() {
		this->life = 0;
	}
	
	Player::Player(int life) {
		this->life = life;
	}
	
	Player::~Player() {}
	
	void Player::act(Actor &a) {
		return;
	}
		
// Private
	int life;