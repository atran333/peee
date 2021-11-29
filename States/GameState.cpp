#include "GameState.hpp"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
    : State(window, states) // pointer to the window
{
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Blue);

}
GameState::~GameState()
{

}

void GameState::update(const float& deltaTime)
{
    this->updateInput(deltaTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        std::cout << "Kanye" << std::endl; //prints kanye when in game state
    }
    
}

void GameState::render(sf::RenderTarget* target)
{
    
    target->draw(this->background);
}

void GameState::updateInput(const float& deltaTime)
{
    this->checkForQuit();
}

void GameState::endState()
{
    std::cout << "Ending GameState!" << std::endl;
}