#ifndef GRAPHICS 
#define GRAPHICS
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <mutex>

struct Tile_t{
    float posX;
    float posY;
    float width;
    float height;
    std::string textureUrl;
};


class Graphics
{
public:
    Graphics (int w, int h, std::string title);
    void setBacground(sf::Color color);
    void setBacground(sf::Texture texture);
    void setBacground(std::string url);
    void draw(sf::RectangleShape rect);
    void draw(Tile_t tile);
    int addTile(Tile_t &tile);
    bool isOpen();
    void removeTile(int tileNr);
    void update();
    void run();
    void stop();


private:
    /* data */
    sf::RenderWindow win;
    sf::Color color;
    sf::Texture texture;
    std::vector<Tile_t> tiles;
    std::thread renThread;
    void run_funk();
    void stop_funk();
    pthread_t thread;
    std::mutex tileMutex;
    bool runnig;
};

#endif
