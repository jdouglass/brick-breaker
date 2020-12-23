#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>

class Platform {
    sf::RectangleShape platform;
    const sf::Vector2f platformDimensions { 200.f, 20.f };
    const float platformVelocity { 6.f };

public:
    Platform();
    
    sf::RectangleShape drawPlatform();
};

#endif