// Powerup.hpp

#ifndef powerup_hpp
#define powerup_hpp

#include "Actor.hpp"

class Powerup : public Actor {
	public:
        Powerup() { this->tile.source = "powerup.png"; }
        ~Powerup() { }
        void act(Actor &a) { }
        virtual Actor::Type getType() { return powerup; }
};

class Life : public Powerup {
	public:
        Life() { this->tile.source = "life.png"; }
        ~Life() { }
        void act(Actor &a) {
            if (a.getType() == Actor::player) {
                a.setLife(a.getLife()+1);
                this->life=0;
                this->xPos = -100;
                this->yPos = -100;
            }
        }
};

class Invincibility : public Powerup {
	public:
        Invincibility() { this->tile.source = "invincible.png"; }
        ~Invincibility() { }
        void act(Actor &a) {
            if (a.getType() == Actor::player) {
                a.setInvincible(500);
                this->life = 0;
                this->xPos = -100;
                this->yPos = -100;
            }
        }
};

#endif
