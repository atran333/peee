#include "../headers/GUIElement.hpp"
#include <SFML/Graphics.hpp>

// GUIText
GUIText::GUIText(sf::Vector2f position, std::string text) {
  sf::Font font;
  font.loadFromFile("fonts/OpenSans.ttf");
  this->message = text;
  this->position = position;

}

void GUIElement::draw(sf::RenderWindow* target) {

}