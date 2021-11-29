#include "MainMenuState.hpp"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states)
    : State(window, states) // pointer to the window
{
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Magenta);
}
MainMenuState::~MainMenuState()
{

}

void MainMenuState::update(const float& deltaTime)
{
    this->updateInput(deltaTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
    {
        std::cout << "Main" << std::endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        this->states->push(new GameState(this->window, this->states));
    }
    
}

void MainMenuState::render(sf::RenderTarget* target)
{

    target->draw(this->background);


}

void MainMenuState::updateInput(const float& deltaTime)
{
    this->checkForQuit();

    
}

void MainMenuState::endState()
{
    std::cout << "Ending MainMenuState!" << std::endl;
}

void MainMenuState::nextStage()
{
    
}