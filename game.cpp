#include "game.h"
#include <iostream>

const float Game::PlayerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

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
    sf::Clock clock; // might delete this
    sf::Time timeSinceLastUpdate = sf::Time::Zero; // might delete this
    while (window.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart(); // might delete this
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
    } else if (key == sf::Keyboard::Space) {
//        std::cout << "Space bar pressed" << std::endl;
        isPlaying = true;
        std::cout << isPlaying << std::endl;
    }
}

void Game::update(sf::Time TimePerFrame) {
    sf::Vector2f platformMovement(0.f, 0.f);
    sf::Vector2f platformPos = platform.getPosition();
    sf::Vector2f ballMovement(0.f, 0.f);
    if (isPlaying) {
        if (platformMovingRight) {
            if (platformPos.x >= 800) {
                platformPos.x = 800.f;
            } else {
                platformMovement.x += 10.f;
            }
        }
        if (platformMovingLeft) {
            if (platformPos.x <= 0) {
                platformPos.x = 0.f;
            } else {
                platformMovement.x -= 10.f;
            }
        }
        platform.move(platformMovement);
    }
}

void Game::render() {
    window.clear();
    window.draw(platform);
    window.draw(ball);
    window.display();
}