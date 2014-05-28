#ifndef BALLSHOOTER_H_INCLUDED
#define BALLSHOOTER_H_INCLUDED

#include "Ball.h"

class BallShooter : public GenericObject
{
private:
    Ball* currentBallPtr;
    bool loaded;
public:
    BallShooter(int, int);
    void shoot();
    void loadBall(Ball&);
    bool isLoaded();
    Ball* getBall();
};

#endif // BALLSHOOTER_H_INCLUDED
