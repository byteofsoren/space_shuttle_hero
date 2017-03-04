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

        void setXVel(double value)     { this->xVel = value; }
        void setYVel(double value)     { this->yVel = value; }
        void setVel(double x, double y){ this->yVel = y; this->xVel = x; }
        void setXPos(double value)     { this->xPos = value; }
        void setYPos(double value)     { this->yPos = value; }
        void setPos(double x, double y){ this->yPos = y; this->xPos = x; }
        void setCR(double value)       { this->cr = value; }

        double getXVel()  { return this->xVel; }
        double getYVel()  { return this->yVel; }
        double getXPos()  { return this->xPos; }
        double getYPos()  { return this->yPos; }
        double getCR()    { return this->cr; }
        Tile_t *getTile() { return &tile; }
};

#endif
