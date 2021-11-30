#include "../headers/GUIButton.hpp"
#include <iostream>

void GUIButton::setOrigins() {
  sf::FloatRect textRect = this->text->getLocalBounds();
  this->text->setOrigin(textRect.left + textRect.width/2.0f,
                        textRect.top + textRect.height/2.0f);

  sf::FloatRect rectRect = this->rect->getLocalBounds();
  this->rect->setOrigin(rectRect.left + rectRect.width/2.0f,
                        rectRect.top + rectRect.height/2.0f);
}

GUIButton::GUIButton(sf::Vector2f position, sf::Vector2f size, std::string text) : GUIRect(position, size), GUIText(position, text) {
};

GUIButton::~GUIButton() {
}

void GUIButton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(*this->rect, states);
  target.draw(*this->text, states);
}

void GUIButton::setStyle(GUIStyle* style) {
  GUIText::setStyle(style);
  this->normalButtonColor = style->buttonColor;
  this->hoveredButtonColor = style->buttonColor - sf::Color(50,50,50,0); 
  this->clickedButtonColor = style->buttonColor - sf::Color(120,120,120,0); 
  this->normalTextColor = style->buttonTextColor;
  this->hoveredTextColor = style->buttonTextColor - sf::Color(50,50,50,0); 
  this->clickedTextColor = style->buttonTextColor - sf::Color(120,120,120,0); 
  setOrigins();
}
  
void GUIButton::update(sf::Event* event, sf::RenderWindow* target) { 
  sf::Vector2i mousePosition = sf::Mouse::getPosition(*target);
  bool mouseInButton =    mousePosition.x >= rect->getPosition().x - rect->getGlobalBounds().width/2
                            && mousePosition.x <= rect->getPosition().x + rect->getGlobalBounds().width/2
                            && mousePosition.y >= rect->getPosition().y - rect->getGlobalBounds().height/2
                            && mousePosition.y <= rect->getPosition().y + rect->getGlobalBounds().height/2;
  if(event->type == sf::Event::MouseMoved) {
      if(mouseInButton) {
          state = State::HOVERED;
      }

      else  {
          state = State::NORMAL;
      }
  }

  if (event->type == sf::Event::MouseButtonPressed) {
      switch(event->mouseButton.button)  {
      case sf::Mouse::Left: {
          if(mouseInButton)   {
              state = State::CLICKED;
          }

          else {
              state = State::NORMAL;
          }
      }
      break;
      }
  }

  if (event->type == sf::Event::MouseButtonReleased) {
      switch(event->mouseButton.button)
      {
        case sf::Mouse::Left:
        {
            if(mouseInButton)
            {
                state = State::HOVERED;
            }

            else
            {
                state = State::NORMAL;
            }
        }
      }  
  }
  switch(this->state) {
      case State::NORMAL: {
          rect->setFillColor(normalButtonColor);
          text->setFillColor(normalTextColor);
          break;
      }
      case State::HOVERED: {
          rect->setFillColor(hoveredButtonColor);
          text->setFillColor(hoveredTextColor);
          break;
      }
      case State::CLICKED: {
          rect->setFillColor(clickedButtonColor);
          text->setFillColor(clickedTextColor);
          break;
      }
  }
}