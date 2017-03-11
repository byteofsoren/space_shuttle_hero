#include "Hud.hpp"

Hud::Hud(int posX, int posY) {
    this->oneTileWidth = 50;
    this->hudTile.posX = posX;
    this->hudTile.posY = posY;
    this->hudTile.source = "health.png";
    this->hudTile.height = 50;      // Height of the file is hard coded....
    this->hudTile.width = oneTileWidth;

}
void Hud::setTileSize(int width, int height) {
    this->oneTileWidth = width;
    this->hudTile.height = height;
}

Tile_t *Hud::getTile() {
    return &this->hudTile;
}

void Hud::update() {
    // this code sets the with of the tile based on how mutch life the actor
    // have.
    this->hudTile.width= this->act->getLife() * oneTileWidth;
    std::cout << "Life :" << act->getLife() << "pos(x=" << hudTile.posX <<
        ", y=" <<hudTile.posY << ") size(w="<< hudTile.width << ", h="
        << hudTile.height << ")" << std::endl;
}
