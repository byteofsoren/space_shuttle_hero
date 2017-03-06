#ifndef game_hpp
#define game_hpp

#include "Graphics.hpp"
#include "Actor.hpp"

class Player;

class Game {
    private:
        Graphics renderer;
        Tile_t p1Life, p2Life;
        std::vector<Actor *> actors;
        Player *p1, *p2;

    public:
        Game();
        ~Game();
        int init();
        int run();
};

#endif
