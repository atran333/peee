#ifndef __GUIBUTTON_H__
#define __GUIBUTTON_H__

#include "GUIElement.hpp"

enum ButtonState{
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
    sf::Color normalButtonColor = sf::Color::Red;
    sf::Color hoveredButtonColor = sf::Color::Blue;
    sf::Color clickedButtonColor = sf::Color::Green;
    sf::Color normalTextColor = sf::Color::Red;
    sf::Color hoveredTextColor = sf::Color::Blue;
    sf::Color clickedTextColor = sf::Color::Green;
    void setOrigins(); 
    ButtonState state;
};

#endif