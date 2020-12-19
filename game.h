#include <SFML/Graphics.hpp>

class Game {
    sf::RenderWindow window;
    sf::RectangleShape platform;
    sf::CircleShape ball;

    bool isPlaying = false;
    bool platformMovingRight = false;
    bool platformMovingLeft = false;
    static const float PlayerSpeed;
    static const sf::Time TimePerFrame;

    void handlePlayerInput(sf::Keyboard::Key, bool);

    void processEvents();
    void update(sf::Time);
    void render();
public:
    Game();

    void run();
};