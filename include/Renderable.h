#ifndef GENERICOBJECT_H_INCLUDED
#define GENERICOBJECT_H_INCLUDED

#include "ObjectState.h"
#include <SFML/Graphics.hpp>
//#include "ImageInfo.h"
#include <iostream>

class GenericObject
{
protected:
    //Image properties
    std::string imageFile;
    sf::Sprite sprite;

    //Physical Properties
    ObjectState state;

public:
    GenericObject();

    //Accessors
    std::string getImageFile();
    ObjectState& getState();
    sf::Sprite& getSprite();

    //Mutators
    void setState(const ObjectState&);
    void setSprite(const sf::Sprite&);
    void setImageFile(const std::string&);
};


#endif // GENERICOBJECT_H_INCLUDED
