#include "ball.h"

Ball::Ball() : ball() {
    ball.setRadius(ballRadius);
    ball.setPosition(475.f, 850.f);
    ball.setFillColor(sf::Color::Red);
}

sf::Vector2f Ball::getPosition() {
    return ball.getPosition();
}

sf::CircleShape Ball::drawBall() {
    return ball;
}

void Ball::moveBall(sf::Vector2f platformPosition) {
    sf::Vector2f ballPos = ball.getPosition();
    ball.move(velocity);
    if (ballPos.x <= 0) {
        velocity.x = ballVelocity;
    } else if (ballPos.x >= 950) {
        velocity.x = -ballVelocity;
    } else if (ballPos.y <= 0) {
        velocity.y = ballVelocity;
    } else if ((ballPos.y == platformPosition.y - 50) && (ballPos.x >= platformPosition.x && ballPos.x <= platformPosition.x + 200)) {
        velocity.y = -ballVelocity;
    }
}
