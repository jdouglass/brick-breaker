#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>

class Platform {
    sf::RectangleShape platform;
    const sf::Vector2f platformDimensions { 80.f, 20.f };
    const float platformVelocity { 6.f };

public:
    Platform(float m_X, float m_Y);
};

#endif