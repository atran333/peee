#include "MainMenuState.hpp"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states)
    : State(window, states) // pointer to the window
{
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    /* USER DEFINED CODE */
    this->background.setFillColor(sf::Color::Cyan);
    GUIStyle* style = new GUIStyle();
    // text style
    style->setFont("fonts/Bubblegum.ttf");
    style->headerSize = 70;
    style->textOutlineSize = 3;
    style->primaryColor = sf::Color::White;
    style->outlineColor = sf::Color(255,204,0);
    // button style
    style->subheadingSize = 60;
    style->buttonColor = sf::Color(255,204,0);
    style->buttonTextColor = sf::Color::Black;

    canvas = new Canvas(style);

    GUIElement* title = new GUIHeadingText(sf::Vector2f(window->getView().getCenter().x, 150.0), "THE BOSS BABY");
    GUIElement* startButton = new GUIButton(sf::Vector2f(window->getView().getCenter().x, window->getView().getCenter().y), sf::Vector2f(270, 100), "START");
    GUIElement* optionsButton = new GUIButton(sf::Vector2f(window->getView().getCenter().x, window->getView().getCenter().y + 120), sf::Vector2f(270, 100), "QUIT");

    canvas->addElement(title);
    canvas->addElement(startButton);
    canvas->addElement(optionsButton);

    /* USER DEFINED CODE END */
}
MainMenuState::~MainMenuState()
{

}

void MainMenuState::update(const float& deltaTime, sf::Event* event, sf::RenderWindow* window)
{
    /* USER DEFINED CODE */

    this->canvas->update(event, window);




    /* USER DEFINED CODE END */

    this->updateInput(deltaTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
    { 
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
