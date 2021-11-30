#include <iostream>
#include "../headers/Canvas.hpp"
#include "../headers/GUIElement.hpp"

void Canvas::addElement(GUIElement* element) {
  element->setStyle(this->style);
  elements.push_back(element);
}

void Canvas::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  if (!visible) {
    return;
  }
  for (unsigned i = 0; i < elements.size(); ++i) {
    target.draw(*elements.at(i));
  }
}

void Canvas::setVisible() {
  this->visible = true;
}

void Canvas::setStyle(GUIStyle* style) {
  this->style = style;
}

void Canvas::setInvisible() {
  this->visible = false;
}
Canvas::~Canvas() {
  for (unsigned i = 0; i < elements.size(); ++i) {
    delete elements.at(i);
  }
  elements.clear();
  delete style;
}

void Canvas::update(sf::Event* event, sf::RenderWindow* target) {
  for (unsigned i = 0; i < elements.size(); ++i) {
    elements.at(i)->update(event, target);
  }
}