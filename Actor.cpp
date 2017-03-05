#include "Actor.hpp"

Actor::Actor() {
    this->xPos = 0.0;
    this->yPos = 0.0;
    this->xVel = 0.0;
    this->yVel = 0.0;
    this->cr = 0.0;
    this->tile.posX = 0.0;
    this->tile.posY = 0.0;
    this->tile.width = 100.0;
    this->tile.height = 150.0;
    this->tile.identifier = "GenericActor";
}

Actor::~Actor() {
    
}

void Actor::update() {
    // Update actor position based on velocities

    this->xPos += this->xVel;
    this->yPos += this->yVel;

    // Update tile position to current position

    this->tile.posX = this->xPos - this->tile.width;
    this->tile.posY = this->yPos - this->tile.height;
}

void Actor::act(Actor &a) {
    return;
}

