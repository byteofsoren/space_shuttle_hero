#ifndef game_hpp
#define game_hpp

#include "Graphics.hpp"
#include "Actor.hpp"
#include "Formation.hpp"
#include <queue>
#include "Hud.hpp"

class Player;
class Projectile;
class Powerup;

struct SpawnPoint {
    sf::Time time;
    Formation* formation;
    int type;
    Powerup *pow;
    SpawnPoint(int t, Formation *f, int s, Powerup *p):time(sf::milliseconds(t)), formation(f), type(s), pow(p)  { }
};

class Game {
    private:
        Graphics renderer;
        Tile_t p1Life, p2Life;
        std::vector<Actor *> actors;
        std::vector<Formation> formations;
        std::queue<SpawnPoint> spawns;
        Player *p1, *p2;
        Projectile *projectiles;
        Powerup *powerups[10];
        sf::Clock gameClock;
        sf::Time goal;
        Hud *hud1, *hud2;
    public:
        Game();
        ~Game();
        int init();
        int run();
};

#endif
