#include "Graphics.hpp"
#include <iostream>
#include <unistd.h>

//#define debug

Graphics::Graphics(int w, int h, std::string title) {
    win.create(sf::VideoMode(w,h), title);
    win.clear(sf::Color::Black);
    win.display();
    if (!font.loadFromFile("/usr/share/fonts/TTF/Vera.ttf")) {
        std::cout << "Error cant font.loadFromFile" << std::endl;
    }
}
bool Graphics::tryUpdate() {
    if (userClosed()) return false;

    win.clear(backColor);
    for (size_t i = 0; i < tiles.size(); i++)
    {
        Tile_t *cTile = tiles[i];
        int tilePosX = cTile->posX;
        int tilePosY = cTile->posY;

        sf::IntRect spRect;
        sf::Texture texture = getTexture(cTile->source);
        sf::Sprite sprite;

        sprite.setPosition(tilePosX,tilePosY);
        if (cTile->width != 0 || cTile->height != 0) {
            // If with or heigt is not 0 then specify a rectangle to render.
            spRect.left = tilePosX;
            spRect.top = tilePosY;
            spRect.width = cTile->width;
            spRect.height = cTile->height;
            texture.setRepeated(true);
            sprite.setTextureRect(spRect);
            sprite.setTexture(texture);
        }else{
            if(cTile->source.size() != 0)sprite.setTexture(texture);
        }
        win.draw(sprite);
        // Draw the text of the tile.
        sf::Text text;
        if (cTile->text.size()) {
#ifdef debug
            std::cout << "Create text" << std::endl;
#endif
            text.setFont(this->font);
            text.setString(cTile->text);
            text.setFillColor(sf::Color::White);
            text.setPosition(cTile->posX, cTile->posY);
            text.setCharacterSize(20);
            win.draw(text);
        }
    }
    win.display();
    return true;
}

void Graphics::addTile(Tile_t *tile) {
    tiles.push_back(tile);
}

void Graphics::removeTile(Tile_t *tile) {
    for (size_t x = 0; x < tiles.size(); x++)
        if (tiles[x] == tile)
        {
            tiles.erase(tiles.begin()+x);
            return;
        }
}

sf::Texture& Graphics::getTexture(std::string url)
{
    std::string gfx_folder = "gfx/";
    
    if (textureStore.count(url) == 0) {
        std::cout << "Test" << std::endl;
        sf::Texture newTexture;
        newTexture.loadFromFile(gfx_folder+url);
        textureStore.insert(std::pair<std::string, sf::Texture>(url,newTexture));
    }

    return textureStore[url];
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
