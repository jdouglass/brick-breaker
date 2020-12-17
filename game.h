#include <SFML/Graphics.hpp>

class Game {
    const int width = 1000;
    const int height = 1000;
    sf::RenderWindow mWindow;
    sf::RectangleShape mPlayer;

    void processEvents();
    void update();
    void render();


public:
    Game();
    void run();
};