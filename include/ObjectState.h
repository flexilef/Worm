#ifndef OBJECTSTATE_H_INCLUDED
#define OBJECTSTATE_H_INCLUDED

class ObjectState
{
private:
    double posX;
    double posY;
    double velocity;
    double acceleration;
    int angle;

public:
    ObjectState();

    //Accessors
    double getPosX();
    double getPosY();
    double getVelocity();
    double getAccleration();
    double getAngle();

    //Mutators
    void setPosition(double, double);
    void setVelocity(double);
    void setAcceleration(double);
    void setAngle(double);

    //Helpers
    void calculateComponents(double&, double&, double, double);
};

#endif // OBJECTSTATE_H_INCLUDED
