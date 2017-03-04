#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include "Graphics.hpp"
#include <iostream>
#include <unistd.h>

void testGraphics()
{
   Graphics window(800,600,"Game on"); //Test
   struct Tile_t rect={200,100,50,50,""};
   struct Tile_t rect2={300,200,50,50,""};
   window.setBacground(sf::Color::Blue);
//   window.draw(rect);
//   window.draw(rect2);
    window.addTile(rect);
    window.addTile(rect2);
   window.update();
   while (window.isOpen()) {
       std::cout << "Showing win"<<std::endl;
       rect.posX ++;
   }

}

int main(/*int argc, char** argv*/) {
    testGraphics();
    return 0;
    Game* g = new Game();
    int res;
    
    if ((res = g->init())) {
        res = g->run();
    }

    res = (res > 0) ? 0 : -1;            // If res is zero, something went wrong
    delete g;
    return res;

}
