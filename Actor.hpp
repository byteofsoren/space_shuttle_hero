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

        void setXVel(double value)        { this->xVel = value; }
        void setYVel(double value)        { this->yVel = value; }
        void setXPos(double value)        { this->xPos = value; }
        void setYPos(double value)        { this->yPos = value; }
        void setCR(double value)          { this->cr = value; }
        void setTile(const Tile_t& value) { this->tile = value; }

        const double getXVel()  { return this->xVel; }
        const double getYVel()  { return this->yVel; }
        const double getXPos()  { return this->xPos; }
        const double getYPos()  { return this->yPos; }
        const double getCR()    { return this->cr; }
        const Tile_t& getTile() { return this->tile; }
};

#endif
