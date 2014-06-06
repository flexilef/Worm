#ifndef WORM_H
#define WORM_H

#include "ObjectState.h"
#include "Ball.h"

class Worm : public Renderable
{
private:
    ObjectState state;
    std::vector<Ball> body;
    Ball head;

    bool dead;
    int length;

public:
    Worm();
    virtual ~Worm();

    void moveWorm();
    void addBall(Ball);
    void removeBall(Ball);
    //accessors
    int getLength();
    bool isDead();
};

#endif // WORM_H
