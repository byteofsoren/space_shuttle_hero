#ifndef ACTOR_H
#define ACTOR_H

#include "Graphics.hpp"

class Actor {
    protected:
        Tile_t gfx;
        int xPos, yPos;                // Position
        int xVel, yVel;                // Velocity
        double cr;                     // Collision radius
    public:
        void move();
        void draw();
        virtual void act(Actor &a);
}

#endif
