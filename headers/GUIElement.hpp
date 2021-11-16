#ifndef __GUIELEMENT_H__
#define __GUIELEMENT_H__

#include <SFML/Graphics.hpp>
#include <string.h>
#include <vector>

class GUIElement {
  public:
    GUIElement() : position(sf::Vector2f(0,0)) {};
    GUIElement(sf::Vector2f position) : position(position) {};
    ~GUIElement();
    void setPosition(sf::Vector2f position) {this->position = position;};
    sf::Vector2f getPosition() {return this->position;}
    virtual void draw(sf::RenderWindow* target) = 0;
  private:
    sf::Vector2f position;
};

class GUIText : public GUIElement {
  public:
    GUIText();
    GUIText(sf::Vector2f position, std::string text) : GUIElement(position), message(text) {};
    virtual void draw(sf::RenderWindow* target) = 0;
  private:
    sf::Vector2f position;
    std::string message;
};

class GUIShape : public GUIElement {
  public:
    GUIShape();
    GUIShape(sf::Vector2f position) : GUIElement(position){};
    virtual void draw(sf::RenderWindow* target) = 0;
  private:
    sf::Vector2f position;
    sf::RectangleShape rect;
};

class GUIButton : public GUIElement {
  public:
    GUIButton();
    GUIButton(sf::Vector2f position, std::string text) : GUIElement(position), message(text) {};
    virtual void draw(sf::RenderWindow* target) = 0;
    void clickInteration();
  private:
    sf::Vector2f position;
    std::string message;
    sf::RectangleShape rect;
};
#endif