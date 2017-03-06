#ifndef game_hpp
#define game_hpp

#include "Graphics.hpp"
#include "Actor.hpp"

class Game {
    private:
        Tile_t obj1, obj2;
        Graphics renderer;
        std::vector<Actor *> actors;
    /*  Actor p1;
        Actor p2;*/
    
    public:
        Game();
        ~Game();
        int init();
        int run();
};

#endif
