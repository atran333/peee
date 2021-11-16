#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

// class that acts as the game engine
class Game
{
  public:
     //constructors / deconstructors
     Game();
     virtual ~Game();
     //accessor
     const bool running() const;
     //functions
     void pollEvents();
     void update();
     void render();
  private:
     //variables
     //Window
     sf::RenderWindow* window;
     sf::VideoMode videoMode;
     sf::Event event;
     //private func
     void initializeVariables();
     void initializeWindow();
};
#endif // GAME_H