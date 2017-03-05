#ifndef GRAPHICS
#define GRAPHICS
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>

struct Tile_t{
    float posX;
    float posY;
    float width;
    float height;
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
    void startThreads(){runThread = std::thread(&Graphics::run_funk, this);}
    void removeTile(int tileNr);
    void addTile(Tile_t *tile);


private:
    /* data */
    sf::RenderWindow win;
    sf::Color backColor;
    sf::Texture backTexture;
    std::vector<Tile_t *> tiles;
    std::thread runThread;
    void run_funk();
    void stop_funk();
    pthread_t thread;
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
