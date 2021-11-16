#include <iostream>

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace std;
//decon / construct
Game::Game()
{
    this->initializeVariables();
    this->initializeWindow();
}

Game::~Game()
{
    delete this->window;
}
// private funcs
void Game::initializeVariables()
{
    this->window = nullptr; //want to be able to delete window (dynamically alloc)

    
}
void Game::initializeWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    //sf::Window window(sf::VideoMode(800, 600), "SFML Window");
    this->window = new sf::RenderWindow(this->videoMode, "Dungeon Crawler", sf::Style::Titlebar | sf::Style::Close);

    
}
//accessor 
const bool Game::running() const
{
    return this->window->isOpen();
}
//functions
void Game::pollEvents()
{
    while (this->window->pollEvent(this->event))
        {
            switch(this->event.type) // each event is going to have a type, so its gonna switch any data that comes w that
            {
               // "close requested" event: we close the window
              case sf::Event::Closed:
                      this->window->close();
              case sf::Event::KeyPressed:
                  if(this->event.key.code == sf::Keyboard::Escape)
                      this->window->close();
                  break;
            }
           
        }

}
void Game::update()
{
     //behind logic 
     this->pollEvents();
     

}
void Game::render()
{
    /*
        -clear old frame
        renders objects
        display fram in window 
        renders game object
    */
    // outputing the pixels
    this->window->clear(sf::Color(255,255,255));
    //draw game objects
    this->window->display();
    
}