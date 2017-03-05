#include "Actor.hpp"
#include <chrono>

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
    lastUpdate = std::chrono::system_clock::now();
}

Actor::~Actor() {
}

void Actor::update() {
    std::chrono::time_point<std::chrono::system_clock> currentClock = std::chrono::system_clock::now();

    std::chrono::duration<double> difference = currentClock - lastUpdate;
    // Update actor position based on velocities
    setXPos(xPos + xVel * difference.count());
    setYPos(yPos + yVel * difference.count());

    lastUpdate = currentClock;
}

void Actor::act(Actor &a) {
    return;
}

