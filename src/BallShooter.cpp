#include "../include/BallShooter.h"

BallShooter::BallShooter(int x, int y)
{
    imageFile = "ball.png";
    state.setPosition(x, y);

    //load first ball
    Ball firstBall(x, y, sf::Color::Red);
    currentBallPtr = &firstBall;
    loaded = true;
}

void BallShooter::shoot()
{
    double angle = state.getAngle();

    currentBallPtr->getState().setAngle(angle);
    currentBallPtr->getState().setVelocity(.1);

    //currentBallPtr = NULL;
    loaded = false;
}

void BallShooter::loadBall(Ball& ball)
{
    if(&ball != NULL)
    {
        currentBallPtr = &ball;
        loaded = true;
    }
}

bool BallShooter::isLoaded()
{
    return loaded;
}

Ball* BallShooter::getBall()
{
    return currentBallPtr;
}
