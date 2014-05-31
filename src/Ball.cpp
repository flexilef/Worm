#include "../include/Ball.h"

#include <iostream>
#include <cmath>

Ball::Ball()
{
    imageFile = "whiteBall.png";
    state.setPosition(0, 0);
    destroyed = false;
    setColor(sf::Color::Blue);

}

Ball::Ball(int x, int y, sf::Color c)
{
    imageFile = "whiteBall.png";
    state.setPosition(x,y);
    destroyed = false;
    setColor(c);
}

//{ Accessors

ObjectState& Ball::getState()
{
    return state;
}

sf::Color Ball::getColor()
{
    return color;
}

bool Ball::isDestroyed()
{
    return destroyed;
}
//}

//{ Mutators
void Ball::setDestroyed(bool destroy)
{
    destroyed = destroy;
}

void Ball::setColor(sf::Color c)
{
    color = c;
    sprite.setColor(color);
}
//}

//{ Member Functions

//Updates the ball's position based on it's velocity and angle
void Ball::moveBall()
{
    double posX = state.getPosX();
    double posY = state.getPosY();
    double velocityX = 0;
    double velocityY = 0;

    //Calculate velocityX and velocityY
    state.calculateComponents(velocityX, velocityY, state.getVelocity(), state.getAngle());

    posX += velocityX;
    posY += velocityY;

    state.setPosition(posX, posY);
}
//}
