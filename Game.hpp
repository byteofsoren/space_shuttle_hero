#ifndef game_hpp
#define game_hpp

#include "Graphics.hpp"
#include "Actor.hpp"
#include "Formation.hpp"

class Player;

class Game {
    private:
        Graphics renderer;
        Tile_t p1Life, p2Life;
        std::vector<Actor *> actors;
        std::vector<Player *> players;
        Player *p1, *p2;
        Formation *form;
    public:
        Game();
        ~Game();
        int init();
        int run();
};

#endif
