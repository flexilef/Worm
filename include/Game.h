#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "Ball.h"
#include "BallShooter.h"

//Like the "world"
class Game
{
private:
    int width;
    int height;
    sf::RenderWindow _window;

    Renderer _renderer;
    sf::Clock Clock;

    BallShooter _shooter;
    std::vector<Ball> _balls;

public:
    Game(int, int);
    ~Game();

    void init(); //sets up the current gamestate
    void shutdown();

    void gameLoop();
    void checkGameState();
    void drawEntities();
    void updateEntities();
    void generateLevel(int);

    void handleInput(sf::Event&);
    void handleCollisions();

    float getDeltaT();
};


#endif // GRID_H_INCLUDED
