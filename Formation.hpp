#ifndef formation_h
#define formation_h

#include <vector>
#include <SFML/System.hpp>

class Actor;

class Formation {
    public:
        Formation();
        Formation(int size, int enemyType);
        ~Formation();
        void spawn(int type);
        void update();

        std::vector<Actor*> getEnemies() { return enemies; }

    private:
        sf::Clock clock;
        sf::Time end;
        std::vector<Actor*> enemies;
        bool active;
        int type;
};

#endif
