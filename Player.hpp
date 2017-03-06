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

        int getLife() { return this->life; }
    
	private:
	int life;
	Input input;
};

#endif
