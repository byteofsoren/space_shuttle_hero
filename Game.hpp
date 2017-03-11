#ifndef game_hpp
#define game_hpp

#include "Graphics.hpp"
#include "Actor.hpp"
#include "Formation.hpp"
#include <queue>

class Player;

struct SpawnPoint {
    sf::Time time;
    Formation* formation;
    int type;
    SpawnPoint(int t, Formation* f, int s):time(sf::milliseconds(t)), formation(f), type(s)  { }
};

class Game {
    private:
        Graphics renderer;
        Tile_t p1Life, p2Life;
        std::vector<Actor *> actors;
        std::vector<Player *> players;
        std::vector<Formation> formations;
        std::queue<SpawnPoint> spawns;
        Player *p1, *p2;
        sf::Clock gameClock;
        sf::Time goal;
    public:
        Game();
        ~Game();
        int init();
        int run();
};

#endif
