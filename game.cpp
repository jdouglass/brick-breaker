#include "game.h"
#include "platform.h"

Game::Game() : window(sf::VideoMode(1000, 1000), "Brick Breaker", sf::Style::Close | sf::Style::Titlebar | sf::Style::None)
, platform(), ball() {
    platform.setSize(sf::Vector2f(200.f, 20.f));
    platform.setPosition(400.f, 900.f);
    platform.setFillColor(sf::Color::White);

    ball.setRadius(25.f);
    ball.setPosition(475.f, 850.f);
    ball.setFillColor(sf::Color::Red);
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (window.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::Right) {
        platformMovingRight = isPressed;
    } else if (key == sf::Keyboard::Left) {
        platformMovingLeft = isPressed;
    }
}

void Game::update() {
    sf::Vector2f platformMovement(0.f, 0.f);
    if (platformMovingRight) {
        platformMovement.x += 1.f;
    }
    if (platformMovingLeft) {
        platformMovement.x -= 1.f;
    }
    platform.move(platformMovement);
}

void Game::render() {
    window.clear();
    window.draw(platform);
    window.draw(ball);
    window.display();
}