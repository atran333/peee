#include "../headers/GUIElement.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// GUIText
GUIText::GUIText(sf::Vector2f position, std::string message, GUIStyle* style) {
  this->message = message;
  this->position = position;
  this->text = new sf::Text();

  this->text->setPosition(position);
  this->text->setString(this->message);
  this->text->setFont(style->font);
  this->text->setCharacterSize(style->headerSize);
  this->text->setFillColor(style->primaryColor);
}

GUIText::~GUIText() {
  delete text;
}

void GUIText::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(*this->text); 
}