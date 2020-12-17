#include "game.h"

Game::Game() :
    mWindow(sf::VideoMode(width, height), "Breakout", sf::Style::None | sf::Style::Titlebar | sf::Style::Close), 
    mPlayer() {
        mPlayer.setPosition(400.f, 900.f);
        mPlayer.setSize(sf::Vector2f(200, 20));
        mPlayer.setFillColor(sf::Color::White);
}


void Game::run() {
    while (mWindow.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mWindow.close();
        }
    }
}

void Game::update() {

}

void Game::render() {
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}