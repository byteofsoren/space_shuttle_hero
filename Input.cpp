#include "Input.hpp"

Input::Input() {
    this->upKey = sf::Keyboard::Unknown;
    this->rightKey = sf::Keyboard::Unknown;
    this->downKey = sf::Keyboard::Unknown;
    this->leftKey = sf::Keyboard::Unknown;
    this->shootKey = sf::Keyboard::Unknown;    
}

Input::Input(sf::Keyboard::Key up, sf::Keyboard::Key right,
             sf::Keyboard::Key down, sf::Keyboard::Key left,
             sf::Keyboard::Key shoot) {
    this->upKey = up; 
    this->rightKey = right;
    this->downKey = down;
    this->leftKey = left;
    this->shootKey = shoot;
}

bool Input::up() {
    return isKeyPressed(upKey);
}
bool Input::right() {
    return isKeyPressed(rightKey);
}
bool Input::down() {
    return isKeyPressed(downKey);
}
bool Input::left() {
    return isKeyPressed(leftKey);
}
bool Input::shoot() {
    return isKeyPressed(shootKey);
}
bool Input::isKeyPressed(sf::Keyboard::Key key) {
   if (sf::Keyboard::isKeyPressed(key))
       return true;
   return false;
}

void Input::mapKey(sf::Keyboard::Key k, Buttons b) {
    switch (b) {
        case    Up: this->upKey = k; break;
        case Right: this->rightKey = k; break;
        case  Down: this->downKey = k; break;
        case  Left: this->leftKey = k; break;
        case Shoot: this->shootKey = k; break;
    }
}
