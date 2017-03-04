#include "Graphics.hpp"
#include <iostream>

Graphics::Graphics(int w, int h, std::string title) {
    this->win.create(sf::VideoMode(w,h), title);
    this->win.clear(sf::Color::Black);
    this->win.display();
    this->runnig = 0;
}
void Graphics::setBackground(sf::Color color) {
    this->color = color;
}
void Graphics::setBackground(sf::Texture texture) {
    this->texture = texture;
}
void Graphics::setBackground(std::string url) {
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
bool Graphics::isOpen() {
    //std::cout << "isOpen" << std::endl;
    //std::cout << win.isOpen() << std::endl;
    return win.isOpen();
}
void Graphics::removeTile(int tileNr) {
    this->tileMutex.lock();
    this->tiles.erase(this->tiles.begin() + tileNr);
    this->tileMutex.unlock();
}
void Graphics::update() {
    //win.clear(this->color);    // Need a ifcase for bacground.
    std::vector<Tile_t>::iterator it;
    this->tileMutex.lock();
    for(it = this->tiles.begin(); it != this->tiles.end(); it++){
        sf::RectangleShape rect(sf::Vector2f(it->width, it->height));
        rect.setPosition(it->posX, it->posY);
        this->draw(rect);
    }
    this->win.display();
    this->tileMutex.unlock();
}

void Graphics::run() {
    this->runnig = 1;
    this->renThread = std::thread(&Graphics::run_funk, this);
}

void Graphics::run_funk() {
     while (this->isOpen()) {
        std::cout << "run_funk" << std::endl;
        sf::Event event;
        while (win.pollEvent(event)) {
            if (event.type==sf::Event::Closed) {
                win.close();
                std::cout << "Closed winodw" << std::endl;
                this->runnig = 0;
            }
        }
        this->update();
    }
}
void Graphics::stop() {
    this->runnig = 0;
    this->renThread.join();
}
