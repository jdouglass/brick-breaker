#include "platform.h"

Platform::Platform() {
    platform.setSize(sf::Vector2f(200, 20));
    platform.setFillColor(sf::Color::White);
    platform.setPosition(sf::Vector2f(400, 900));
}

sf::RectangleShape Platform::drawPlatform() {
    return platform;
}