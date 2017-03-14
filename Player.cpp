// player.cpp
#include "Player.hpp"

Player::Player() {
    this->input.mapKey(sf::Keyboard::Up, Input::Up);
    this->input.mapKey(sf::Keyboard::Right, Input::Right);
    this->input.mapKey(sf::Keyboard::Down, Input::Down);
    this->input.mapKey(sf::Keyboard::Left, Input::Left);
    this->input.mapKey(sf::Keyboard::RControl, Input::Shoot);
    this->life = 4;
}

Player::Player(int pNum, int life) {
    this->life = life;

    if (pNum == 0) {
        this->input.mapKey(sf::Keyboard::W, Input::Up);
        this->input.mapKey(sf::Keyboard::D, Input::Right);
        this->input.mapKey(sf::Keyboard::S, Input::Down);
        this->input.mapKey(sf::Keyboard::A, Input::Left);
        this->input.mapKey(sf::Keyboard::Space, Input::Shoot);
        this->tile.source = "spaceship1.png";
    } else {
        this->input.mapKey(sf::Keyboard::Up, Input::Up);
        this->input.mapKey(sf::Keyboard::Right, Input::Right);
        this->input.mapKey(sf::Keyboard::Down, Input::Down);
        this->input.mapKey(sf::Keyboard::Left, Input::Left);
        this->input.mapKey(sf::Keyboard::RControl, Input::Shoot);
        this->tile.source = "spaceship2.png";
    }
}

Player::~Player() {}

void Player::act(Actor &a) {}

void Player::update()
{
	const int speed = 100;

    if (this->xPos < 0) this->xPos = 0;
    if (this->xPos > 800) this->xPos =800;
    if (this->yPos < 0) this->yPos = 0;
    if (this->yPos > 800) this->yPos = 800;

	if (input.up() )
		Actor::yVel = -speed;
	else if (input.down())
		Actor::yVel = speed;
	else
		Actor::yVel *= 0.99;

	if (input.left())
		Actor::xVel = -speed;
	else if (input.right())
		Actor::xVel = speed;
	else
		Actor::xVel *= 0.99;

	Actor::update();
}

bool Player::isShooting() {
    return false;
}
