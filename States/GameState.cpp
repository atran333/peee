#include "GameState.hpp"
#include "MainMenuState.hpp"
GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
    : State(window, states) // pointer to the window
{
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Cyan);

}
GameState::~GameState()
{

}

void GameState::update(const float& deltaTime, sf::Event* event, sf::RenderWindow* window)
{
    this->updateInput(deltaTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        // std::cout << "Kanye" << std::endl; //prints kanye when in game state
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        // std::cout << "Main" << std::endl;
        this->states->push(new MainMenuState(this->window, this->states));
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