// Projectile.hpp
#ifndef projectile_hpp
#define projectile_hpp

#include "Actor.hpp"

class Projectile : public Actor {
	public:
	Projectile();
	Projectile(int owner, int damage);
	~Projectile();
	void act(Actor &a);
	
	private:
	int owner;
	int damage;

};

#endif