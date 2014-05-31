#ifndef BALLSHOOTER_H_INCLUDED
#define BALLSHOOTER_H_INCLUDED

#include "Ball.h"

class BallShooter : public Renderable
{
private:
    ObjectState state;
    Ball* currentBallPtr;
    bool loaded;
public:
    BallShooter(int, int);
    ObjectState& getState();
    void shoot();
    void loadBall(Ball&);
    bool isLoaded();
    Ball* getBall();
};

#endif // BALLSHOOTER_H_INCLUDED
