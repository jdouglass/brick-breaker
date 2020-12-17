#include "game.h"


Game::Game() :
    mWindow(sf::VideoMode(width, height), "Breakout", sf::Style::None | sf::Style::Titlebar | sf::Style::Close), 
    mPlayer() {
        mPlayer.setPosition(400.f, 900.f);
        mPlayer.setSize(sf::Vector2f(200, 20));
        mPlayer.setFillColor(sf::Color::White);
}


void Game::run() {
    sf::Clock clock;
    while (mWindow.isOpen()) {
        processEvents();
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        /*
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            handlePlayerInput(event.key.code);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            handlePlayerInput(event.key.code);
        }
        */
        switch (event.type) {
            case sf::Event::Closed:
                mWindow.close();
                break;
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            default:
                break;
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::Right) {
        movePlatformRight = isPressed;
    }
    if (key == sf::Keyboard::Left) {
        movePlatformLeft = isPressed;
    }
}

void Game::update() {
    sf::Vector2f platformPos = mPlayer.getPosition();
    sf::Vector2f platformMovement (0.f, 0.f);
    if (movePlatformRight) {
        if (platformPos.x >= 800.f) {
            mPlayer.setPosition(800.f,900.f);
        } else {
            platformMovement.x += 0.75f;
        }
    }
    if (movePlatformLeft) {
        if (platformPos.x < 0.f) {
            mPlayer.setPosition(0.f, 900.f);
        } else {
            platformMovement.x -= 0.75f;
        }
    }
    mPlayer.move(platformMovement); 
}

void Game::render() {
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}