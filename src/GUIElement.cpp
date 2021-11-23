#include "../headers/GUIElement.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// GUIText
GUIText::GUIText(sf::Vector2f position, std::string fontDir, std::string message) {
  this->message = message;
  this->position = position;
  this->font = fontDir;

  sf::Text* tempText = new sf::Text();

  if(!this->actualFont.loadFromFile(this->font)) {
    return;
  }
  tempText->setFont(this->actualFont);
  tempText->setPosition(position);
  tempText->setString(this->message);
  tempText->setCharacterSize(25);
  tempText->setFillColor(sf::Color::White);

  this->text = tempText;
}

void GUIText::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(*this->text); 
}