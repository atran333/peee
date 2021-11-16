#include <iostream>
#include "../headers/Canvas.hpp"
#include "../headers/GUIElement.hpp"

void Canvas::addElement(GUIElement* element) {
  elements.push_back(element);
}

void Canvas::draw(sf::RenderWindow* target) {
  for (unsigned i = 0; i < elements.size(); ++i) {
    elements.at(i)->draw(target);
  }
}