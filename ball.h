#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball {
    sf::CircleShape ball;
    const float ballRadius { 25.f };
    const float ballVelocity { 8.f };
    sf::Vector2f velocity { -ballVelocity, -ballVelocity };

public:
    Ball(float m_X, float m_Y);
    sf::CircleShape getDrawableBall();

    void update();
};

#endif