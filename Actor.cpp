#include "Actor.hpp"
#include <chrono>

Actor::Actor() {
    xPos = 0.0;
    yPos = 0.0;
    xVel = 0.0;
    yVel = 0.0;
    collisionRadius = 15.0;
    tile.posX = 0.0;
    tile.posY = 0.0;
    tile.source = "genericActor.png";
    lastUpdate = std::chrono::system_clock::now();
}

void Actor::setTexture(std::string textureSource)
{
    tile.source = textureSource;
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
