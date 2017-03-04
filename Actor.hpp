#ifndef ACTOR_H
#define ACTOR_H

#include "Graphics.hpp"

class Actor {
    protected:
        Tile_t tile;
        double xPos, yPos;                // Position
        double xVel, yVel;                // Velocity
        double cr;                        // Collision radius
    public:
        Actor();
        ~Actor();
        void update();
        virtual void act(Actor &a);

        void setXVel(double value) { this->xVel = value; }
        void setYVel(double value) { this->yVel = value; }

        const Tile_t& getTile() { return this->tile; }
};

#endif
