#ifndef formation_h
#define formation_h

#include <vector>
#include <SFML/System.hpp>

class Actor;

struct BPoint {    // A bezier point, complete with coefficients
    float x;
    float y;
    int coefficient;
    BPoint(float xPos, float yPos, int coef) : x(xPos), y(yPos), coefficient(coef) { }
};

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
        std::vector<BPoint> points;
        std::vector<int> coefficients;
        bool active;
        int type;
};

#endif
