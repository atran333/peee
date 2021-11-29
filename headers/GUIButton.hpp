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
  private:
    void setOrigins(); 
    State state;
};

#endif