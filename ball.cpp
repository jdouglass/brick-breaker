#include "ball.h"

Ball::Ball(float m_X, float m_Y) : ball() {
    ball.setRadius(ballRadius);
    ball.setPosition(m_X, m_Y);
    ball.setFillColor(sf::Color::Red);
}

sf::CircleShape Ball::drawBall() {
    return ball;
}

void Ball::update() {
    sf::Vector2f ballPos = ball.getPosition();
    ball.move(velocity);
    if (ballPos.x <= 0) {
        velocity.x = ballVelocity;
    } else if (ballPos.x >= 950) {
        velocity.x = -ballVelocity;
    } else if (ballPos.y <= 0) {
        velocity.y = ballVelocity;
    } else if (ballPos.y >= 850) {
        velocity.y = -ballVelocity;
    }
}
