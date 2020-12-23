#include "platform.h"

Platform::Platform(float m_X, float m_Y) {
    platform.setSize(sf::Vector2f(200, 20));
    platform.setFillColor(sf::Color::White);
    platform.setPosition(sf::Vector2f(450, 900));
}