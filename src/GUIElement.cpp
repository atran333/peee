#include "../headers/GUIElement.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// GUIText
GUIText::GUIText(sf::Vector2f position, sf::Font font, std::string text) {
  this->message = text;
  this->position = position;
  this->font = &font;
  std::cout << message << std::endl;
}

void GUIText::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  sf::Text txt;
  // txt.setFont(*this->font);

  sf::Font test;
  if(!test.loadFromFile("fonts/OpenSans.ttf")) {
    return;
  }
  txt.setFont(test);

  txt.setString(message);
  txt.setCharacterSize(24);
  txt.setFillColor(sf::Color::White);
  target.draw(txt); 
}