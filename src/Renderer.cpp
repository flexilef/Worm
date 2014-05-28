#include "../include/Renderer.h"

Renderer::Renderer(sf::RenderWindow* window)
{
    _windowPtr = window;
}

Renderer::~Renderer()
{
    //TODO
    //delete _windowPtr;
}

void Renderer::init()
{
}

void Renderer::shutdown()
{
}

//Loads an image file by generating a texture and inserting it
//into the imageToTexture map
int Renderer::loadImage(const std::string& filename)
{
    sf::Texture texture;
    bool duplicate = false;

    //check for if empty first
    if(!imageToTexture.empty())
    {
        for(int i=0; i<imageToTexture.size(); i++)
        {
            //check for duplicate filename key
            if(imageToTexture.count(filename))
            {
                duplicate = true;
                return -1;
            }
        }
    }

    if(duplicate == false)
    {
        //load the file
        if(!texture.loadFromFile("images/" + filename))
            return -1;

        //add to the map
        imageToTexture.insert(std::pair<std::string, sf::Texture>(filename, texture));
    }

    return 0;
}

//Loads the image of the object and sets up a sprite for the object
int Renderer::loadObject(GenericObject& object)
{
    std::string filename = object.getImageFile();

    //load the image if not already loaded
    if(loadImage(filename) < 0)
    {
        object.getSprite().setTexture(imageToTexture[filename]);
    }
    else
    {
        return -1;
    }

    return 0;
}

void Renderer::render(GenericObject& object)
{
    int posX = object.getState().getPosX();
    int posY = object.getState().getPosY();

    //load the object to set up the sprite for use
    if(!(loadObject(object) < 0))
    {
            object.getSprite().setPosition(posX, posY);
            _windowPtr->draw(object.getSprite());
    }
}

bool Renderer::alreadyLoaded(GenericObject& object)
{
    std::string filename = object.getImageFile();
    if(imageToTexture.count(filename))
    {
        return true;
    }

    return false;
}

void Renderer::clearScreen()
{
    _windowPtr->clear();
}
