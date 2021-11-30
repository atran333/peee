#ifndef __GUIBUTTON_H__
#define __GUIBUTTON_H__

#include "GUIElement.hpp"

enum State {
  NORMAL,
  HOVERED,
  CLICKED
};

class GUIButton : public GUIText, public GUIRect {
  public:
    GUIButton(); 
    ~GUIButton();
    GUIButton(sf::Vector2f position, sf::Vector2f size, std::string text);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void setStyle(GUIStyle* style);
    virtual void update(sf::Event* event, sf::RenderWindow* target);
  private:
    sf::Color normalColor = sf::Color::Red;
    sf::Color hoveredColor = sf::Color::Blue;
    sf::Color clickedColor = sf::Color::Green;
    void setOrigins(); 
    State state;
};

#endif