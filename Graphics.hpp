#ifndef GRAPHICS 
#define GRAPHICS
#include <SFML/Graphics.hpp>
#include <iostream>

struct Tile_t{
    float posX;
    float posY;
    float witdth;
    float height;
    std::string textureUrl;
};


class Graphics
{
public:
    Graphics (int w, int h, std::string title);
    virtual ~Graphics ();
    void setBacground(sf::Color color);
    void setBacground(sf::Texture texture);
    void setTiles(std::vector<Tile_t> *tiles);
    void update();


private:
    /* data */
    sf::RenderWindow win;
    sf::Color color;
    sf::Texture texture;
    std::vector<Tile_t> *tiles;

};

#endif
