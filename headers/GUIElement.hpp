#ifndef __GUIELEMENT_H__
#define __GUIELEMENT_H__

#include <SFML/Graphics.hpp>
#include <string.h>
#include "GUIStyle.hpp"

class GUIElement : public sf::Drawable {
  public:
    GUIElement() : position(sf::Vector2f(0,0)) {};
    GUIElement(sf::Vector2f position) : position(position) {};
    void setPosition(sf::Vector2f position) {this->position = position;};
    sf::Vector2f getPosition() {return this->position;}
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
    virtual void setStyle(GUIStyle* style) = 0;
  private:
    sf::Vector2f position;
};

class GUIText : virtual public GUIElement {
  public:
    GUIText();
    ~GUIText();
    GUIText(sf::Vector2f position, std::string text);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void setStyle(GUIStyle* style);
  protected:
    sf::Vector2f position;
    sf::Text *text;
    std::string message;
};

class GUIHeadingText : public GUIText {
  public:
    GUIHeadingText();
    ~GUIHeadingText();
    GUIHeadingText(sf::Vector2f position, std::string text) : GUIText(position, text) {};
    virtual void setStyle(GUIStyle* style);
};

class GUISubheadingText : public GUIText {
  public:
    GUISubheadingText();
    ~GUISubheadingText();
    GUISubheadingText(sf::Vector2f position, std::string text) : GUIText(position, text) {};
    virtual void setStyle(GUIStyle* style);
};

class GUIRect : virtual public GUIElement {
  public:
    GUIRect();
    GUIRect(sf::Vector2f position, sf::Vector2f size);
    void setStyle(GUIStyle* style);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  protected:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::RectangleShape* rect;
};
#endif