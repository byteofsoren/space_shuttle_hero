// Powerup.hpp

#ifndef powerup_hpp
#define powerup_hpp

#include "Actor.hpp"

class Powerup : public Actor {
	public:
	Powerup();
	~Powerup();
	void act(Actor &a);
	
};

class Life : public Powerup {
	public:
	Life();
	~Life();
	void act(Actor &a);
}

class Ammo : public Powerup {
	public:
	Ammo();
	~Ammo();
	void act(Actor &a);
}

#endif