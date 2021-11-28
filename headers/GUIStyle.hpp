#ifndef __GUISTYLE_H__
#define __GUISTYLE_H__

#include <SFML/Graphics.hpp>
#include <string>

struct GUIStyle {
  // variables
  GUIStyle();
  sf::Font font;
  std::string fontDir = "fonts/OpenSans.ttf";
  sf::Color primaryColor = sf::Color::Green;
  sf::Color secondaryColor = sf::Color::White;
  sf::Color tertiaryColor = sf::Color::Black;
  int headerSize = 25;
  int subheadingSize = 15;
  int outlineSize = 0;

  // setters
  void setPrimaryColor(sf::Color color) {this->primaryColor = color;}
  void setSecondaryColor(sf::Color color) {this->secondaryColor = color;}
  void setTertiaryColor(sf::Color color) {this->tertiaryColor = color;}
  void setHeaderSize(int size) {this->headerSize = size;}
  void setSubheadingSize(int size) {this->subheadingSize = size;}
  void setOutlineSize(int size) {this->outlineSize = size;}
  void setFont(std::string newFontDir);
};

#endif