#include <cmath>
#include "Formation.hpp"
#include "Enemy.hpp"

Formation::Formation() {
    this->end = sf::seconds(1);
}

Formation::Formation(int size, int enemyType) : Formation() {
    for (int i=0; i < size; i++) {
        switch (enemyType) {
            
            //case 0: this->enemies.push_back(new WeakEnemy()); break;
            //case 1: this->enemies.push_back(new StrongEnemy()); break;
            default: this->enemies.push_back(new Enemy()); break;
        }
    }
}

Formation::~Formation() { }

void Formation::spawn(int type=0) {
    this->type = type;
    this->active = true;
    this->points.clear();
    
    // Set up the formation bezier vertices based on the type

    // This is based on Pascal's triangle, e.g.
    // Rank:
    //   0                     1
    //   1                   1   1 
    //   2                 1   2   1 
    //   3               1   3   3   1 
    //   4             1   4   6   4   1 
    //   5           1   5  10  10   5   1 
    //   6         1   6  15  20  15   6   1 
    //   7       1   7  21  35  35  21   7   1 
    //   8     1   8  28  56  70  56  28   8   1 
    //   9   1   9  36  84 126 126  84  36   9   1 

    for (auto e : this->enemies) {
        e->setXPos(-40);
        e->setYPos(-40);
        e->setLife(1);
    }
    
    switch (type) {
        case 0:
            this->points.push_back(BPoint(0.0f,0.0f,1));
            this->points.push_back(BPoint(800.0f,800.0f,1));
            this->end = sf::seconds(2);
            break;
        case 1:
            this->points.push_back(BPoint(0.0f,0.0f,1));
            this->points.push_back(BPoint(400.0f,800.0f,2));
            this->points.push_back(BPoint(800.0f,0.0f,1));
            this->end = sf::seconds(1);
            break;
        case 2:
            this->points.push_back(BPoint(900.0f,400.0f,1));
            this->points.push_back(BPoint(-500.0f,0.0f,3));
            this->points.push_back(BPoint(1300.0f,0.0f,3));
            this->points.push_back(BPoint(-100.0f,400.0f,1));
            this->end = sf::seconds(3);
            break;
        default:
            break;
    }
    
    this->clock.restart();
}

void Formation::update() {
    double t, ct, x, y;
    int i, j, n;
    const double dt = 0.2;
    bool defeated = true;
    
    if (this->active) {
        t = ((double)this->clock.getElapsedTime().asMilliseconds() / this->end.asMilliseconds());

        if (t < 1 + this->enemies.size()*dt) {
            i = 0;
            n = this->points.size()-1;

            for (auto e : this->enemies) {
                ct = t-0.2*i;

                if (e->getLife() < 1) {
                    e->setXPos(-100);
                    e->setYPos(-100);
                } else {
                    this->powSpotX = e->getXPos();
                    this->powSpotY = e->getYPos();
                    defeated = false;
                }
                
                x = 0;
                y = 0;
                j = 0;

                ct = (ct < 0.0) ? 0.0 : ct;
                ct = (ct > 1.0) ? 1.0 : ct;

                for (auto p : this->points) {
                    x += p.coefficient * std::pow(1-ct,n-j)*std::pow(ct,j) * p.x;
                    y += p.coefficient * std::pow(1-ct,n-j)*std::pow(ct,j) * p.y;

                    j++;
                }

                e->setXPos(x);
                e->setYPos(y);
                
                i++;
            }

            if (defeated) {
                this->active = false;
                this->pow->setXPos(this->powSpotX);
                this->pow->setYPos(this->powSpotY);
            }
        } else {
            this->active = false;
        }
    }
}
