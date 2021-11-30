#include "MainMenuState.hpp"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states)
    : State(window, states) // pointer to the window
{
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Magenta);
    /* USER DEFINED CODE */
    style = new GUIStyle();
    canvas = new Canvas(style);
    std::cout << "created main menu" << std::endl;
    GUIElement* button1 = new GUIButton(sf::Vector2f(window->getView().getCenter().x, window->getView().getCenter().y), sf::Vector2f(100, 50), "Start");
    canvas->addElement(button1);
    /* USER DEFINED CODE END */
}
MainMenuState::~MainMenuState()
{

}

void MainMenuState::update(const float& deltaTime, sf::Event* event, sf::RenderWindow* window)
{
    this->canvas->update(event, window);
    this->updateInput(deltaTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
    {
        // std::cout << "Main" << std::endl;
    
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
       this->states->push(new GameState(this->window, this->states));
    }
    
    
}

void MainMenuState::render(sf::RenderTarget* target)
{

    target->draw(this->background);
    target->draw(*this->canvas);

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
