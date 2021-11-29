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
  sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "SFML window");

  GUIStyle* style = new GUIStyle();

  Canvas canvas(style);
  GUIText* text1 = new GUIHeadingText(sf::Vector2f(100,100), "It's finally working holy shit");
  GUIText* text2 = new GUISubheadingText(sf::Vector2f(400,300), "Hello, World");
  GUIRect* rect1 = new GUIRect(sf::Vector2f(0,0), sf::Vector2f(100, 100));
  canvas.addElement(text1);
  canvas.addElement(text2);
  canvas.addElement(rect1);
  while (window->isOpen()) {
    window->draw(canvas);
    window->display();
    sf::Event* currEvent = new sf::Event();
      while (window->pollEvent(*currEvent))
      {
          // "close requested" event: we close the window
          if (currEvent->type == sf::Event::Closed)
              window->close();
      }
  }

  delete window;
  return 0;
}