#include "../headers/GUIElement.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// GUIText
GUIText::GUIText(sf::Vector2f position, std::string message) {
  this->message = message;
  this->position = position;
  this->text = new sf::Text();

  this->text->setPosition(position);
  this->text->setString(this->message);
}

GUIText::~GUIText() {
  delete text;
}

void GUIText::setStyle(GUIStyle* style) {
  this->text->setFont(style->font);
  this->text->setCharacterSize(style->subheadingSize);
  this->text->setFillColor(style->primaryColor);
  this->text->setOutlineThickness(style->textOutlineSize);
  this->text->setOutlineColor(style->outlineColor);
}

void GUIText::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(*this->text); 
}

// GUIHedingText
void GUIHeadingText::setStyle(GUIStyle* style) {
  GUIText::setStyle(style);
  this->text->setCharacterSize(style->headerSize);
}

GUIHeadingText::~GUIHeadingText() {
  delete text;
}

// GUISubheadingText
void GUISubheadingText::setStyle(GUIStyle* style) {
  GUIText::setStyle(style);
  this->text->setCharacterSize(style->subheadingSize);
}

GUISubheadingText::~GUISubheadingText() {
  delete text;
}

// GUIShape
GUIRect::GUIRect(sf::Vector2f position, sf::Vector2f size) : GUIElement(position), size(size) {
  this->rect = new sf::RectangleShape;
  this->rect->setSize(this->size);
}

void GUIRect::setStyle(GUIStyle* style) {
  this->rect->setFillColor(style->secondaryColor);
  this->rect->setOutlineThickness(style->shapeOutlineSize);
  this->rect->setOutlineColor(style->outlineColor);
}

void GUIRect::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(*this->rect);
}