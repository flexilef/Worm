#include "../include/Game.h"
#include "../src/Collision.cpp"
#include <cstdlib>
#include <sstream>

Grid::Grid(int w, int h) : _renderer(&_window), _shooter(w/2-30, h-60)
{
    width = w;
    height = h;
    _window.create(sf::VideoMode(width, height), "Boomball!!!");

    init();
}

Grid::~Grid() {}

void Grid::init()
{
    generateLevel(1);
}

void Grid::shutdown()
{

}

void Grid::gameLoop()
{
    //debugging stuff here
    std::stringstream ss;
    sf::Font font;
    if (!font.loadFromFile("Sansation.ttf"))
    {
        // error...
    }
    sf::Text text1;
    sf::Text text2;
    // select the font
    text1.setFont(font); // font is a sf::Font
    text2.setFont(font);
    // set the character size
    text1.setCharacterSize(24); // in pixels, not points!
    // set the color
    text1.setColor(sf::Color::Red);

    //real gameloop here
    while(_window.isOpen())
    {
        sf::Event event;
        while(_window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                shutdown(); //take care of any other tasks
                _window.close();
            }

            handleInput(event);
        }
        _window.clear();

        updateEntities();
        drawEntities();
        handleCollisions();

        //only here to display the angle of the shooter for debug
        double angle = _shooter.getState().getAngle();
        std::stringstream ss1,ss2;
        ss1 << angle;
        // set the string to display
        text1.setString(ss1.str());
        text1.setPosition(0,100);
        _window.draw(text1);
        ss2 << _balls.size();
        text2.setString(ss2.str());
        text2.setPosition(0, 150);
        _window.draw(text2);

        _window.display();
    }
}

void Grid::updateEntities()
{
    for(int i=0; i<_balls.size(); i++)
    {
        _balls[i].moveBall();
    }

    //Note: for circletest and boundingboxtest, it seems as if they collide right form the start
    //if(Collision::BoundingBoxTest(_balls[0].getSprite(),_balls[1].getSprite()))
}

void Grid::drawEntities()
{
    int posX, posY;
    int numOfBalls = _balls.size();

    //draw the shooter
    _renderer.render(_shooter);

    //draw the balls
    for(int i=0; i<numOfBalls; i++)
    {
        posX = _balls[i].getState().getPosX();
        posY = _balls[i].getState().getPosY();

        if(posX <= 300 && posX >= 0 && posY <= 400 && posY >= 0)
        {
            _renderer.render(_balls[i]);
        }
    }
}

float Grid::getDeltaT()
{
    Clock.restart();
    double deltaT = Clock.restart().asSeconds();

    return deltaT;
}

void Grid::handleInput(sf::Event& event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Space)
        {
            if(_shooter.isLoaded())
            {
                _shooter.shoot();
                _balls.push_back(*_shooter.getBall());
            }
            else
            {
                double x = _shooter.getState().getPosX();
                double y =_shooter.getState().getPosY();

                Ball newBall(x-50, y-50, sf::Color::Green);
                _shooter.loadBall(newBall);
                _shooter.shoot();
                _balls.push_back(newBall); //note you need to shoot before pushing ball else wont shoot
            }
        }
    }

    double angle = _shooter.getState().getAngle();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(angle > -180)
            angle-=5;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(angle < 0)
            angle+=5;

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        angle = -90;
    }
    _shooter.getState().setAngle(angle);
}

void Grid::handleCollisions()
{
    int currentBallIndex = 0;
    for(int i=0; i<_balls.size(); i++)
    {
        currentBallIndex = _balls.size()-1;
        //_balls[i] is the last ball in the vector, ie the last ball we shot
        if(Collision::PixelPerfectTest(_balls[currentBallIndex].getSprite(),_balls[i].getSprite()))
        {
            _balls[currentBallIndex].getState().setVelocity(.01);
            // Collision::CircleTest()
        }
    }
}

void Grid::generateLevel(int level)
{
    srand(time(NULL));
    int randColor = 0;

    //Generate Level
    for(int j=0; j<4*level; j++)
    {
        randColor = rand()%5;
        Ball theBall(j*50, 0, sf::Color::Blue);

        if(randColor == 0)
            theBall.setColor(sf::Color::Red);
        else if(randColor == 1)
            theBall.setColor(sf::Color::Green);
        else if(randColor == 2)
            theBall.setColor(sf::Color::Blue);
        else
            theBall.setColor(sf::Color::Yellow);

        theBall.getState().setVelocity(0);

        //add the balls to our list
        _balls.push_back(theBall);
    }
}
