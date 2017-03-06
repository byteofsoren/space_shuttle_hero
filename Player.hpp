// player.hpp
#ifndef player_hpp
#define player_hpp

#include "Actor.hpp"
#include "Input.hpp"

class Player : public Actor {
	public:
	Player(int life, sf::Keyboard::Key up = sf::Keyboard::Up, sf::Keyboard::Key right = sf::Keyboard::Right, sf::Keyboard::Key down = sf::Keyboard::Down, sf::Keyboard::Key left = sf::Keyboard::Left, sf::Keyboard::Key shoot = sf::Keyboard::Space) : input{up, right, down, left, shoot}
	{
		this->life = life;
	}
	~Player();
	void act(Actor &a){}
	void update();
	
	private:
	int life;
	Input input;
};

#endif