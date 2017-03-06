// player.cpp
#include "Player.hpp"

Player::~Player() {return;}

void Player::update()
{
	const int speed = 100;
	if (input.up())
		Actor::yVel = -speed;
	else if (input.down())
		Actor::yVel = speed;
	else
		Actor::yVel = 0;

	if (input.left())
		Actor::xVel = -speed;
	else if (input.right())
		Actor::xVel = speed;
	else
		Actor::xVel = 0;

	Actor::update();
}