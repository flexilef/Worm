#ifndef GENERICOBJECT_H_INCLUDED
#define GENERICOBJECT_H_INCLUDED

#include "ObjectState.h"
#include <SFML/Graphics.hpp>
//#include "ImageInfo.h"
#include <iostream>

class Renderable
{
protected:
    //Image properties
    std::string imageFile;
    sf::Sprite sprite;
    ObjectState imageState;

public:
    Renderable();

    //Accessors
    std::string getImageFile();
    sf::Sprite& getSprite();
    ObjectState& getImageState();

    //Mutators
    void setSprite(const sf::Sprite&);
    void setImageFile(const std::string&);
    void setImageState(ObjectState);
};


#endif // GENERICOBJECT_H_INCLUDED
