#include "../headers/GUIStyle.hpp"
#include <iostream>

GUIStyle::GUIStyle() {
  if(!this->font.loadFromFile(fontDir)) {
    return;
  }
}

void GUIStyle::setFont(std::string newFontDir) {
  if(!this->font.loadFromFile(newFontDir)) {
    return;
  }
  this->fontDir = newFontDir;
}

void GUIStyle::setButtonColor(sf::Color newColor) {
  buttonColor = newColor;
  hoveredColor = newColor - sf::Color(50,50,50,0);
  clickedColor = newColor - sf::Color(120,120,120,0);
}