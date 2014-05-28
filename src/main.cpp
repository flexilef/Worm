#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/Game.h"
#include "../include/Ball.h"

/*
 *LIST OF BOTTLENECKS ENCOUNTERED AND REMINDERS
 *1. Drawing things beyond the window dimensions
 *2. Pushing back on a vector that has reached maximum space
 *3. Calling too many functions to load textures/assets
 */

int main()
{
    Grid theGrid(300, 400);
    theGrid.gameLoop();

    return 0;
}
