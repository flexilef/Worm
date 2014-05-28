#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Renderable.h"

class Ball : public GenericObject
{
private:
    sf::Color color;
    bool destroyed;

public:
    Ball();
    Ball(int, int, sf::Color);

    //Member Functions
    void moveBall();

    //Accessors
    sf::Color getColor();
    bool isDestroyed();

    //Mutators
    void setColor(sf::Color);
    void setDestroyed(bool);

    //overload == operator
    Ball& operator=(Ball);

};


#endif // BALL_H_INCLUDED
