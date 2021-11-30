#include <iostream>

#include "../header/Game.hpp"


//decon / construct
Game::Game()
{
    this->initializeVariables();
    this->initializeWindow();
    this->initializeStates();
}

Game::~Game()
{
    delete this->window;
    while(!this->states.empty())
    {
        delete this->states.top(); // removes data the pointer is holding
        this->states.pop(); // removes the actual pointer
    }
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
sf::RenderWindow* Game::getWindow()
{
    return this->window;
}
void Game::initializeStates()
{
    // & -> address of the pointer
    this->states.push(new MainMenuState(this->window, &this->states)); 

}
//accessor 
const bool Game::running() const
{
    return this->window->isOpen();
}
//functions
void Game::updateSFMLEvents()
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
     this->updateSFMLEvents();

     if(!this->states.empty())
     {
         this->states.top()->update(this->deltaTime);

         if(this->states.top()->getQuit())
         {
             this->states.top()->endState();
             delete this->states.top();
             this->states.pop();
         }
     }
     //Application end
     else
     {
        this->endApplication();
        this->window->close();
     }

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
    
    //render items
    if(!this->states.empty())
    {
        this->states.top()->render(this->window);
    }
    //draw game objects
    this->window->display();
    
}
void Game::updateDeltaTime()
{
    // updates deltaTime with the time it takrs to update and render one frame 
    this->deltaTime = this->deltaTimeClock.restart().asSeconds(); // restart resets timer
}
void Game::endApplication()
{
    std:: cout << "Ending Application!" << "/n";
}
