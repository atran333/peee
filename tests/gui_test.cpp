#include <iostream>
#include <SFML/Graphics.hpp>
#include "../headers/Canvas.hpp"

using namespace std;

#define DEBUG 1

#if DEBUG
  #define LOG(x) (cout << x << endl)
#else
  #define LOG(x) 
#endif

int main() {
  LOG("hello world.");
  Canvas test();
  sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML window");
  Canvas canvas;
  sf::Font font;
  if (!font.loadFromFile("fonts/OpenSans.ttf")) {
    LOG("font not found.");
    return 0;
  }
  GUIText* text = new GUIText(sf::Vector2f(100,100), font, "Lets fucking go");
  // // creating test text
  sf::Text txt;
  txt.setFont(font);
  txt.setString("Hello world");
  txt.setCharacterSize(24);
  txt.setFillColor(sf::Color::White);
  // // test text
  // canvas.addElement(text);
  while (window->isOpen()) {
    // canvas.draw(window);
    window->draw(*text);
    // window->draw(txt);
    window->display();
  }
  return 0;
}