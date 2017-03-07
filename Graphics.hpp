#ifndef GRAPHICS
#define GRAPHICS
#include <SFML/Graphics.hpp>
#include <iostream>

struct Tile_t{
    int posX;
    int posY;
    std::string source;
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
    void removeTile(Tile_t *tile);
    void addTile(Tile_t *tile);


private:
    /* data */
    std::map<std::string, sf::Texture> textureStore;
    sf::Texture& getTexture(std::string url);
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
