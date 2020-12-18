#include <SFML/Graphics.hpp>

class Game {
    sf::RenderWindow window;
    sf::RectangleShape platform;
    sf::CircleShape ball;

    bool platformMovingRight = false;
    bool platformMovingLeft = false;

    void handlePlayerInput(sf::Keyboard::Key, bool);

    void processEvents();
    void update();
    void render();
public:
    Game();

    void run();
};