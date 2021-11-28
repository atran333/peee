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