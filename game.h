#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "ball.h"
#include "platform.h"

class Game {
    sf::RenderWindow window;
    Ball ball;
    Platform platform;

    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

    bool isMovingRight;
    bool isMovingLeft;

    void processEvents();
    void update(sf::Time);
    void render();
    void handlePlayerInput(sf::Keyboard::Key, bool);


public:
    Game();
    void run();

};

#endif