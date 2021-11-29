#ifndef GAME_HPP
#define GAME_HPP

#include "../States/GameState.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <vector>


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector> 

// class that acts as the game engine
class Game
{
  public:
     //constructors / deconstructors
     Game();
     virtual ~Game();
     //functions
     void endApplication();
     void updateSFMLEvents();
     void update();
     void render();
     void run();
     void updateDeltaTime();
  private:
     //variables
     float deltaTime;
     std::stack<State*> states;
     //Window
     sf::Clock deltaTimeClock;
     sf::RenderWindow* window;
     sf::VideoMode videoMode;
     sf::Event event;
     //private func
     void initializeVariables();
     void initializeWindow();
     void initializeStates();
};
#endif // GAME_HPP
