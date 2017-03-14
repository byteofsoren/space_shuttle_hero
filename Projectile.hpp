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
        this->tile.source = "shots.png";
    }
    
	Projectile(int owner, int damage) : Actor() {
        this->owner = owner;
        this->life = 1;
        this->damage = damage;
        this->tile.source = "shots.png";
    }
    
	~Projectile() { }

	void act(Actor &a) {
        if (a.getType() == Actor::enemy) {
            std::cout << "EnemyCrash!" << std::endl;
        }
    }

    Actor::Type getType() { return Actor::projectile; }
    
	private:
	    int owner;
        int damage;
};

#endif
