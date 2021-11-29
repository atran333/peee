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
  sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "SFML window", sf::Style::Titlebar);

  GUIStyle* style = new GUIStyle();
  style->subheadingSize = 30;

  Canvas canvas(style);

  // GUIElement* text1 = new GUIHeadingText(sf::Vector2f(0,0), "It's finally working holy shit");
  // GUIElement* text2 = new GUISubheadingText(sf::Vector2f(400,300), "Hello, World");
  // GUIElement* rect1 = new GUIRect(sf::Vector2f(0,0), sf::Vector2f(100, 100));
  GUIElement* button1 = new GUIButton(sf::Vector2f(window->getView().getCenter().x, window->getView().getCenter().y), sf::Vector2f(100, 50), "Start");
  GUIElement* button2 = new GUIButton(sf::Vector2f(1000,100), sf::Vector2f(200, 100), "Quit");

  // canvas.addElement(text1);
  // canvas.addElement(text2);
  // canvas.addElement(rect1);
  canvas.addElement(button1);
  canvas.addElement(button2);
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