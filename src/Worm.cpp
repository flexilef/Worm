#include "../include/Worm.h"

Worm::Worm()
{
    body.push_back(head);
    length = 1;
    dead = false;
}

Worm::~Worm()
{
    //dtor
}

void Worm::moveWorm()
{
    for(int i = 0; i<length; i++)
    {
        body[i].moveBall();
    }
}

//{ Accessors
int Worm::getLength()
{
    return length;
}

bool Worm::isDead()
{
    return dead;
}
//}
