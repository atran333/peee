#include "../headers/GUIElement.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// GUIText
GUIText::GUIText(sf::Vector2f position, std::string fontDir, std::string message) {
  this->message = message;
  this->position = position;
  this->font = fontDir;

  if(!this->actualFont.loadFromFile(this->font)) {
    return;
  }
  this->text = new sf::Text();
  this->text->setFont(this->actualFont);
  this->text->setPosition(position);
  this->text->setString(this->message);
  this->text->setCharacterSize(25);
  this->text->setFillColor(sf::Color::White);
}

void GUIText::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(*this->text); 
}