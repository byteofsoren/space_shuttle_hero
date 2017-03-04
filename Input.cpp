#include "Input.hpp"

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


