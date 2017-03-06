#ifndef ACTOR_H
#define ACTOR_H

#include "Graphics.hpp"
#include <chrono>
#include <math.h>

class Actor {
    protected:
        Tile_t tile;
        double xPos, yPos;                // Position
        double xVel, yVel;                // Velocity
        double collisionRadius;            // Collision radius
        std::chrono::time_point<std::chrono::system_clock> lastUpdate;               // mSec since last update()
    public:
        Actor();
        ~Actor();
        virtual void update();
        virtual void act(Actor &a);

        bool collidesWith(Actor* other);

        void setXVel(double value)     { xVel = value; }
        void setYVel(double value)     { yVel = value; }
        void setVel(double x, double y){ yVel = y; this->xVel = x; }
        void setXPos(double value)     { xPos = value; tile.posX = value - collisionRadius; }
        void setYPos(double value)     { yPos = value; tile.posY = value - collisionRadius; }
        void setPos(double x, double y){ setXPos(x); setYPos(y); }
        void setCR(double value)       { collisionRadius = value; }

        double getXVel()  { return xVel; }
        double getYVel()  { return yVel; }
        double getXPos()  { return xPos; }
        double getYPos()  { return yPos; }
        double getCR()    { return collisionRadius; }
        Tile_t *getTile() { return &tile; }
	void setTexture(std::string textureSource);
};

#endif
