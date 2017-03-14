// Projectile.cpp

#include "Actor.hpp"
#include "Projectile.hpp"

// Public
	Projectile::Projectile(){
		this->owner = 0;
		this->damage = 0;
	}
	
	Projectile::Projectile(int owner, int damage){
		this->owner = owner;
		this->damage = damage;
	}
	
	Projectile:: ~Projectile(){}
	
	void Projectile::act(Actor &a){
		
	}