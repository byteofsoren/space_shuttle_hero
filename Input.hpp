#ifndef INPUT_H
#define INPUT_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Input
{
private:    
    sf::Keyboard::Key upKey;
    sf::Keyboard::Key rightKey;
    sf::Keyboard::Key downKey;
    sf::Keyboard::Key leftKey;
    sf::Keyboard::Key shootKey;
    bool isKeyPressed(sf::Keyboard::Key key);

public:
    enum Buttons {Up, Right, Down, Left, Shoot};

    Input();
    Input(sf::Keyboard::Key up, sf::Keyboard::Key right,
          sf::Keyboard::Key down, sf::Keyboard::Key left,
          sf::Keyboard::Key shoot);
    bool up();
    bool right();
    bool down();
    bool left();
    bool shoot();

    void mapKey(sf::Keyboard::Key k, Buttons b);
};

#endif /* INPUT_H */
