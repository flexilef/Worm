#include "../include/Renderable.h"

GenericObject::GenericObject()
{
}

//{ Accessors
std::string GenericObject::getImageFile()
{
    return imageFile;
}

ObjectState& GenericObject::getState()
{
    return state;
}

sf::Sprite& GenericObject::getSprite()
{
    return sprite;
}
//}

//{ Mutators
void GenericObject::setImageFile(const std::string& filename)
{
    imageFile = filename;
}

void GenericObject::setState(const ObjectState& state)
{
    this->state = state;
}

void GenericObject::setSprite(const sf::Sprite& sprite)
{
    this->sprite = sprite;
}
//}
