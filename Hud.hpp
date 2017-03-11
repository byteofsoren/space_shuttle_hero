#ifndef HUD_H
#define HUD_H
#include "Graphics.hpp"
#include "Player.hpp"
#include "Actor.hpp"
#include <iostream>
#include <vector>

class Hud
{
private:
    Tile_t hudTile;
    Tile_t hudTextTile;
    Actor *act;
    int oneTileWidth;

public:
    Hud(int posX, int posY);
    void setTileSize(int with, int height);
    //virtual ~Hud();
    Tile_t *getTile();
    Tile_t *getTextTile() {return &this->hudTextTile;}
    void conectActor(Actor &act) {this->act = &act;}
    void update();
};

#endif /* HUD_H */
