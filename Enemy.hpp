// enemies.hh 
#ifndef enemy_hpp
#define enemy_hpp

#include "Actor.hpp"
#include "Player.hpp"

class Enemy : public Actor {
public:
	Enemy();
	Enemy(int life, int damage);
	~Enemy();
	void act(Actor &a);
    virtual void act(Player &a);
    
private:
	int damage;
};

#endif
