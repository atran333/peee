#include "GameState.hpp"

GameState::GameState(sf::RenderWindow* window)
    : State(window) // pointer to the window
{


}
GameState::~GameState()
{

}

void GameState::update(const float& deltaTime)
{
    this->updateKeyBinds(deltaTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        std::cout << "Kanye" << "/n" ;
    }
    
}

void GameState::render(sf::RenderTarget* target)
{

}

void GameState::updateKeyBinds(const float& deltaTime)
{
    this->checkForQuit();
}

void GameState::endState()
{
    std::cout << "Ending GameState!" << "/n" ;
}