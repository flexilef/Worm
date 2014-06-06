#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Renderable.h"

class Ball : public Renderable
{
private:
    ObjectState state;
    sf::Color color;
    bool destroyed;

public:
    Ball();
    Ball(int, int, sf::Color);
    Ball(ObjectState);

    //Member Functions
    void moveBall();

    //Accessors
    ObjectState& getState();
    sf::Color getColor();
    bool isDestroyed();

    //Mutators
    void setColor(sf::Color);
    void setDestroyed(bool);
};


#endif // BALL_H_INCLUDED
