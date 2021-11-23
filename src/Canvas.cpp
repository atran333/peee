#include <iostream>
#include "../headers/Canvas.hpp"
#include "../headers/GUIElement.hpp"

void Canvas::addElement(GUIElement* element) {
  elements.push_back(element);
}

// void Canvas::draw(sf::RenderWindow* target) {
//   if (!visible) {
//     return;
//   }
//   for (unsigned i = 0; i < elements.size(); ++i) {
//     elements.at(i)->draw(target);
//   }
// }

void Canvas::setVisible() {
  this->visible = true;
}

void Canvas::setInvisible() {
  this->visible = false;
}
Canvas::~Canvas() {
  for (auto it = elements.begin(); it != elements.end(); ++it) {
    delete *it;
  }
}