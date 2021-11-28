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
  sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML window");

  GUIStyle* style = new GUIStyle();
  style->primaryColor = sf::Color::Magenta;

  Canvas canvas(style);
  GUIText* text1 = new GUIText(sf::Vector2f(100,100), "It's finally working holy shit");
  GUIText* text2 = new GUIText(sf::Vector2f(400,300), "Hello, World");
  canvas.addElement(text1);
  canvas.addElement(text2);
  while (window->isOpen()) {
    window->draw(canvas);
    // window->draw(*text1);
    window->display();
  }

  delete window;
  return 0;
}