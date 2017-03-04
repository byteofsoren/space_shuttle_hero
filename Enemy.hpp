// enemies.hh 
#ifndef enemy_hpp
#define enemy_hpp

#include "Actor.hpp"

class Enemy : public Actor {
	public:
	Enemy();
	Enemy(int life, int damage);
	~Enemy();
	void act(Actor &a);
	
	private:
	int life;
	int damage;
};

#endif
