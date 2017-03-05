#include "Graphics.hpp"
#include <iostream>
#include <unistd.h>

Graphics::Graphics(int w, int h, std::string title) {
    win.create(sf::VideoMode(w,h), title);
    win.clear(sf::Color::Black);
    win.display();
}
bool Graphics::tryUpdate() {
    if (userClosed()) return false;

    win.clear(backColor);
    for (size_t i = 0; i < tiles.size(); i++)
    {
        Tile_t *cTile = tiles[i];
        int tileWidth = cTile->width;
        int tileHeight = cTile->height;
        int tilePosX = cTile->posX;
        int tilePosY = cTile->posY;

        sf::RectangleShape rect(sf::Vector2f(tileWidth, tileHeight));
        rect.setPosition(tilePosX, tilePosY);
        draw(rect);
    }
    win.display();
    return true;
}

void Graphics::addTile(Tile_t *tile) {
    tiles.push_back(tile);
}

//DEBUG

/*int main () {
    Tile_t a = {250, 250, 10, 10, ""};
    Tile_t b = {500, 500, 10, 10, ""};
    std::cout << "Hello World";
    Graphics renderer (800, 800, "Space Shuttle Hero");
    //renderer.addTile(obj1);

    //sf::RectangleShape rect(sf::Vector2f(50, 50));
    //rect.setPosition(20, 20);
    //renderer.draw(rect);

    renderer.addTile(&a);
    renderer.addTile(&b);

    renderer.startThreads();


    for (int i = 50; i < 1000; i++) {
        a.posX += 1;
        std::cout << a.posX << std::endl;
        usleep(10000);
    }
    //while (renderer.isOpen()) {}
}
*/
