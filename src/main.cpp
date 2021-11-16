#include <iostream>
#include "Game.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;

#define DEBUG 1

#if DEBUG
  #define LOG(x) (cout << x << endl)
#else
  #define LOG(x) 
#endif



int main()
{
    //Initialize Game Engine
    Game game;

    
    //texture.loadFromFile("me.png"); 
    //sf::Sprite sprite(texture);
    // Game loop
    while (game.running())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        // window.draw(sprite);
       
        
        //update
        game.update();
        //render
        game.render();
    }

    return 0;
}
