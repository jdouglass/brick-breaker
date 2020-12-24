#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>

class Platform {
    sf::RectangleShape platform;

public:
    Platform();
    
    sf::RectangleShape drawPlatform();
    void movePlatform(sf::Vector2f);
};

#endif