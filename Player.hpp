// player.hpp
#ifndef player_hpp
#define player_hpp

#include "Actor.hpp"
#include "Input.hpp"

class Player : public Actor {
	public:
        Player();
        Player(int pNum, int life);
	    ~Player();
        void act(Actor &a);
	    void update();
        bool isShooting(sf::Time t);
        virtual Actor::Type getType() { return Actor::player; }

        friend class Enemy;
    
    protected:
        sf::Time shotLimit;
	    Input input;
};

#endif
