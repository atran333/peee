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
  GUIText* text = new GUIText(sf::Vector2f(100,100), "fonts/OpenSans.ttf", "Hello world!");
  while (window->isOpen()) {
    // canvas.draw(window);
    window->draw(*text);
    // window->draw(txt);
    window->display();
  }
  return 0;
}