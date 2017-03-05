#include "Actor.hpp"
#include <time.h>

Actor::Actor() {
    xPos = 0.0;
    yPos = 0.0;
    xVel = 0.0;
    yVel = 0.0;
    cr = 0.0;
    tile.posX = 0.0;
    tile.posY = 0.0;
    tile.width = 100.0;
    tile.height = 150.0;
    tile.identifier = "GenericActor";
    lastUpdate = clock();
}

Actor::~Actor() {
}

void Actor::update() {
    clock_t currentClock = clock();
    double velocityMultiplicant = (currentClock - lastUpdate) / 1000;
    // Update actor position based on velocities
    setXPos(xPos + xVel * velocityMultiplicant);
    setYPos(yPos + yVel * velocityMultiplicant);

    lastUpdate = currentClock;
}

void Actor::act(Actor &a) {
    return;
}

