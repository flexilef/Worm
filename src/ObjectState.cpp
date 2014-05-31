#include "../include/ObjectState.h"
#include <cmath>

ObjectState::ObjectState()
{
    posX = 0;
    posY = 0;
    angle = 0;
    velocity = 0;
    acceleration = 0;
}

//{ Accessors
double ObjectState::getPosX()
{
    return posX;
}

double ObjectState::getPosY()
{
    return posY;
}

double ObjectState::getVelocity()
{
    return velocity;
}

double ObjectState::getAccleration()
{
    return acceleration;
}

//Returns the angle the object is currently facing,
//where 0 = +x and 180 = -x
double ObjectState::getAngle()
{
    return angle;
}
//}

//{ Mutators
void ObjectState::setPosition(double x, double y)
{
    posX = x;
    posY = y;
}

void ObjectState::setVelocity(double v)
{
    velocity = v;
}

void ObjectState::setAcceleration(double a)
{
    acceleration = a;
}

void ObjectState::setAngle(double degrees)
{
    angle = degrees;
}
//}

//{ Helpers
//Calculates the x and y components of a given value and angle, and stores the results into
//xComponent and yComponent
void ObjectState::calculateComponents(double& xComponent, double& yComponent, double value, double angle)
{
    const double PI = 3.14159265358979323846;

    xComponent = value*cos(angle*PI/180);
    yComponent = value*sin(angle*PI/180);
}
//}
