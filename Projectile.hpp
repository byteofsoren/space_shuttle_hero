// Projectile.hpp
#ifndef projectile_hpp
#define projectile_hpp

#include "Actor.hpp"

class Projectile : public Actor {
	public:
	Projectile() {
        this->owner = 0;
        this->life = 0;
        this->damage = 1;
        this->yVel = -300;
        this->tile.source = "shots.png";
    }
    
	Projectile(int owner, int damage) : Actor() {
        this->owner = owner;
        this->life = 1;
        this->damage = damage;
        this->yVel = -300;
        this->tile.source = "shots.png";
    }
    
   	~Projectile() { }

	void act(Actor &a) {
        if (a.getType() == Actor::enemy) {
            a.setLife(0);
            a.setXPos(-100);
            this->life = 0;
        }
    }

    Actor::Type getType() { return Actor::projectile; }
    
	private:
	    int owner;
        int damage;
};

#endif
