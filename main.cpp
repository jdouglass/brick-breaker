#include "ball.h"
#include "platform.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
	Ball ball{475, 850};
	Platform platform;
	sf::RenderWindow window{{1000, 1000}, "Brick Breaker", sf::Style::Close | sf::Style::None | sf::Style::Titlebar};
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(false);

	while(window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear(sf::Color::Black);
		ball.update();
		window.draw(ball.drawBall());
		window.draw(platform.drawPlatform());
		window.display();
	}
	return 0;
}