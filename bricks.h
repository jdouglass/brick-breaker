#ifndef BRICKS_H
#define BRICKS_H

#include <SFML/Graphics.hpp>

class Bricks {
    std::vector<sf::RectangleShape> bricks(int);

    void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;



};

#endif