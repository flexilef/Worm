#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Renderable.h"

class Renderer
{
private:
    //std::vector<std::string> imageFiles;
    std::map<std::string, sf::Texture> imageToTexture;
    sf::RenderWindow* _windowPtr;
public:
    Renderer(sf::RenderWindow*);
    ~Renderer();

    void init();
    void shutdown();
    int loadImage(const std::string&);
    int loadObject(Renderable&);
    void render(Renderable&);
    void clearScreen();
    bool alreadyLoaded(Renderable&);
};

#endif // RENDERER_H
