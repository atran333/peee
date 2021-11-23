#include "../headers/GUIElement.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// GUIText
GUIText::GUIText(sf::Vector2f position, std::string fontDir, std::string text) {
  this->message = text;
  this->position = position;
  this->font = fontDir;
}

void GUIText::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  sf::Text txt;
  sf::Font font;
  if(!font.loadFromFile(this->font)) {
    return;
  }
  txt.setFont(font);
  txt.setPosition(position);
  txt.setString(message);
  txt.setCharacterSize(25);
  txt.setFillColor(sf::Color::White);
  target.draw(txt); 
}