#ifndef __CANVAS_H__
#define __CANVAS_H__

#include <SFML/Graphics.hpp>
#include <string.h>
#include <vector>
#include "GUIElement.hpp"

class Canvas : public sf::Drawable {
  private:
    bool visible = true; 
    std::vector<GUIElement*> elements;
  public:
    Canvas() {};
    ~Canvas();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void setVisible();
    void setInvisible();
    void addElement(GUIElement* element);
    void draw(sf::RenderWindow* target);
};

#endif