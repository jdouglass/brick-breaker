#include "platform.h"

Platform::Platform() : platform() {
    platform.setSize(sf::Vector2f(200, 20));
    platform.setFillColor(sf::Color::White);
    platform.setPosition(sf::Vector2f(400, 900));
}

sf::Vector2f Platform::getPosition() {
    return platform.getPosition();
}

sf::RectangleShape Platform::drawPlatform() {
    return platform;
}

void Platform::movePlatform(sf::Vector2f platformMovement) {
    sf::Vector2f platformPosition = platform.getPosition();
    if (platformPosition.x < 0) {
        platform.setPosition(0.f, 900.f);
    } else if (platformPosition.x > 800) {
        platform.setPosition(800.f, 900.f);
    } else {
        platform.move(platformMovement);
    }
}