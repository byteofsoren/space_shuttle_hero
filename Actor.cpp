#include "Actor.hpp"

Actor::Actor() {
    this->xPos = 0.0;
    this->yPos = 0.0;
    this->xVel = 0.0;
    this->yVel = 0.0;
    this->cr = 0.0;
}

Actor::~Actor() {
    
}

void Actor::update() {
    // Update actor position based on velocities

    this->xPos += this->xVel;
    this->yPos += this->yVel;

    // Update tile position to current position

    this->gfx.posX = this->xPos - this->gfx.width;
    this->gfx.posY = this->yPos - this->gfx.height;
}

void Actor::act(Actor &a) {
    return;
}
