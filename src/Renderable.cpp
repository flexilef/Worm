#include "../include/Renderable.h"

Renderable::Renderable()
{
}

//{ Accessors
std::string Renderable::getImageFile()
{
    return imageFile;
}

sf::Sprite& Renderable::getSprite()
{
    return sprite;
}

ObjectState& Renderable::getImageState()
{
    return imageState;
}
//}

//{ Mutators
void Renderable::setImageFile(const std::string& filename)
{
    imageFile = filename;
}

void Renderable::setSprite(const sf::Sprite& sprite)
{
    this->sprite = sprite;
}
//}
