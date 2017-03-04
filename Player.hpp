// player.hpp
#ifndef player_hpp
#define player_hpp

#include "Actor.hpp"

class Player : public Actor {
	public:
	Player();
	Player(int life);
	~Player();
	void act(Actor &a);
	
	private:
	int life;
};

#endif