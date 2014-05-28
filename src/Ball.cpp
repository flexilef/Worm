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

Ball& Ball::operator=(Ball rhs)
{
    //check for self assignment
    if(this == &rhs)
        return *this;

    //TODO: make a swap function with all the code below

    rhs.setState(this->getState());
    rhs.setSprite(this->getSprite());
    rhs.setImageFile(this->getImageFile());
    rhs.setDestroyed(this->isDestroyed());
    rhs.setColor(this->getColor());

    return *this;
}

//{ Accessors
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
//not sure if better to use helper function (prob yes, since recyclable) or just do it in the function
void Ball::moveBall()
{
    const double PI = 3.14159265358979323846;

    double posX = state.getPosX();
    double posY = state.getPosY();
    double velocity = state.getVelocity();
    double angle = state.getAngle();

    double velocityX = velocity*cos(angle*PI/180);
    double velocityY = velocity*sin(angle*PI/180);

    //Calculate velocityX and velocityY
    //state.calculateComponents(velocityX, velocityY, state.getVelocity(), state.getAngle());

    posX += velocityX;
    posY += velocityY;

    state.setPosition(posX, posY);
}
//}
