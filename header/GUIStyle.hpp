#ifndef __GUISTYLE_H__
#define __GUISTYLE_H__

#include <SFML/Graphics.hpp>
#include <string>

struct GUIStyle {
  // variables
  GUIStyle();
  sf::Font* font;
  std::string fontDir = "fonts/OpenSans.ttf";
  sf::Color primaryColor = sf::Color::Green;
  sf::Color secondaryColor = sf::Color::Blue;
  sf::Color tertiaryColor = sf::Color::Red;
  sf::Color outlineColor = sf::Color::White; 
  int headerSize = 40;
  int subheadingSize = 15;
  float textOutlineSize = 0;
  float shapeOutlineSize = 0;
  sf::Color buttonColor = sf::Color::Red;
  sf::Color buttonTextColor = sf::Color::White;

  // setters
  void setFont(std::string newFontDir);
  void setButtonColor(sf::Color newColor);
};

#endif