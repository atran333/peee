#include "../header/GUIStyle.hpp"
#include <iostream>

GUIStyle::GUIStyle() {
  font = new sf::Font();
  if(!this->font->loadFromFile(fontDir)) {
    return;
  }
}

void GUIStyle::setFont(std::string newFontDir) {
  sf::Font* tempFont = this->font;
  this->font = new sf::Font(); 
  if(!this->font->loadFromFile(newFontDir)) {
    delete font;
    this->font = tempFont;
    return;
  }
  delete tempFont;
  this->fontDir = newFontDir;
}
