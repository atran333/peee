#include "../headers/GUIButton.hpp"

void GUIButton::setOrigins() {
  sf::FloatRect textRect = this->text->getLocalBounds();
  this->text->setOrigin(textRect.left + textRect.width/2.0f,
                        textRect.top + textRect.height/2.0f);

  sf::FloatRect rectRect = this->rect->getLocalBounds();
  this->rect->setOrigin(rectRect.left + rectRect.width/2.0f,
                        rectRect.top + rectRect.height/2.0f);
}

GUIButton::GUIButton(sf::Vector2f position, sf::Vector2f size, std::string text) : GUIRect(position, size), GUIText(position, text) {
};

GUIButton::~GUIButton() {
}

void GUIButton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(*this->rect, states);
  target.draw(*this->text, states);
}

void GUIButton::setStyle(GUIStyle* style) {
  GUIText::setStyle(style);
  this->rect->setFillColor(style->buttonNormalColor);
  setOrigins();
}