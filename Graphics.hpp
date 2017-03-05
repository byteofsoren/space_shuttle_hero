#ifndef GRAPHICS
#define GRAPHICS
#include <SFML/Graphics.hpp>
#include <iostream>

struct Tile_t{
    int posX;
    int posY;
    int width;
    int height;
    std::string identifier;
};


class Graphics
{
public:
    Graphics (int w, int h, std::string title);
    ~Graphics(){};
    void setBackground(sf::Color color){backColor = color;}
    void setBackground(sf::Texture texture){backTexture = texture;}
    void draw(sf::RectangleShape rect){win.draw(rect);}
    bool isOpen(){return win.isOpen();}
    bool tryUpdate(); //Redraw all tiles from
    void removeTile(int tileNr);
    void addTile(Tile_t *tile);


private:
    /* data */
    sf::RenderWindow win;
    sf::Color backColor;
    sf::Texture backTexture;
    std::vector<Tile_t *> tiles;
    bool userClosed() {
        sf::Event event;
        if (win.pollEvent(event)) {
            if (event.type==sf::Event::Closed) {
                win.close();
                return true;
            }
        }
        return false;
    }
};

#endif
