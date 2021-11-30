#include "GameState.hpp"
#include "MainMenuState.hpp"
GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
    : State(window, states) // pointer to the window
{
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));

    /* USER DEFINED CODE */
    this->background.setFillColor(sf::Color::Yellow);

    texture = new sf::Texture();
    texture->loadFromFile("tempassets/bossbaby.jpg");
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(sf::Vector2f(20,20));

    gme = new GameObject(*texture, *sprite,sf::Vector2f(window->getView().getCenter().x, window->getView().getCenter().y), "");

    /* USER DEFINED CODE END */
}
GameState::~GameState()
{

}

void GameState::update(const float& deltaTime, sf::Event* event, sf::RenderWindow* window)
{
    /* USER DEFINED CODE */


    window->display();
    window->clear();


    /* USER DEFINED CODE END */


    this->updateInput(deltaTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        this->states->push(new MainMenuState(this->window, this->states));
    }
    
}

void GameState::render(sf::RenderTarget* target)
{
    target->draw(this->background);
    target->draw(gme->getSprite());
}

void GameState::updateInput(const float& deltaTime)
{
    this->checkForQuit();
}

void GameState::endState()
{
    std::cout << "Ending GameState!" << std::endl;
}