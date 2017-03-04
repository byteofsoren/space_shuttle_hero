#include <iostream>
#include "Graphics.hpp"

Graphics::Graphics(int w, int h, std::string title) {
    this->win.create(sf::VideoMode(w,h), title);
    this->win.clear(sf::Color::Black);
    this->runnig = 0;
}
void Graphics::setBacground(sf::Color color) {
    this->color = color;
}
void Graphics::setBacground(sf::Texture texture) {
    this->texture = texture;
}
void Graphics::setBacground(std::string url) {
    sf::Texture texture;
    if (!texture.loadFromFile(url)) {
            std::cout<<"Error loading from file" <<std::endl;
            exit(EXIT_FAILURE);
    }
    this->texture = texture;
}
void Graphics::draw(sf::RectangleShape rect) {
    this->win.draw(rect);
}
void Graphics::draw(Tile_t tile) {
    sf::RectangleShape rect(sf::Vector2f(tile.width, tile.height));
    rect.setPosition(tile.posX, tile.posY);
    this->draw(rect);
}
int Graphics::addTile(Tile_t &tile) {
    this->tileMutex.lock();
    this->tiles.push_back(tile);
    this->tileMutex.unlock();
    return this->tiles.size();
}
void Graphics::removeTile(int tileNr) {
    this->tileMutex.lock();
    this->tiles.erase(this->tiles.begin() + tileNr);
    this->tileMutex.unlock();
}
void Graphics::update() {
    std::vector<Tile_t>::iterator it;
    this->tileMutex.lock();
    for(it = this->tiles.begin(); it != this->tiles.end(); it++){
        sf::RectangleShape rect(sf::Vector2f(it->width, it->height));
        rect.setPosition(it->posX, it->posY);
        this->draw(rect);
    }
    this->tileMutex.unlock();
}

void Graphics::run() {
    this->runnig = 1;
    this->renThread = std::thread(&Graphics::run_funk, this);
}

void Graphics::run_funk() {
     while (this->runnig) {
        this->update();
    }
}
void Graphics::stop() {
    this->runnig = 0;
}
