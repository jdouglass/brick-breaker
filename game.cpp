#include "game.h"

Game::Game() : window(sf::VideoMode(1000, 1000), "Brick Breaker", sf::Style::Close | sf::Style::Titlebar | sf::Style::None) {
    isMovingLeft = false;
    isMovingRight = false;
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(window.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
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
        isMovingRight = isPressed;
    } else if (key == sf::Keyboard::Left) {
        isMovingLeft = isPressed;
    }
}

void Game::update(sf::Time TimePerFrame) {
    sf::Vector2f platformMovement(0.f, 0.f);
    sf::Vector2f platformPosition = platform.getPosition();
    sf::Vector2f ballPosition = ball.getPosition();
    if (isMovingRight) {
        platformMovement.x += 8.f;
    }
    if (isMovingLeft) {
        platformMovement.x -= 8.f;
    }
    platform.movePlatform(platformMovement);
    ball.moveBall(platformPosition);
}

void Game::render() {
    window.clear();
    window.draw(platform.drawPlatform());
    window.draw(ball.drawBall());
    window.display();
}