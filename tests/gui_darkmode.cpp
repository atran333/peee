#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/Canvas.hpp"

using namespace std;

#define DEBUG 1

#if DEBUG
  #define LOG(x) (cout << x << endl)
#else
  #define LOG(x) 
#endif

int main() {
  sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML window", sf::Style::Titlebar);

  GUIStyle* style = new GUIStyle();
  // text style
  style->headerSize = 100;
  style->textOutlineSize = 3;
  style->primaryColor = sf::Color::White;
  style->outlineColor = sf::Color(80,80,80);
  // button style
  style->subheadingSize = 70;
  style->buttonColor = sf::Color(80,80,80);
  style->buttonTextColor = sf::Color::White;

  Canvas canvas(style);

  GUIElement* title = new GUIHeadingText(sf::Vector2f(window->getView().getCenter().x, 150.0), "VIDEOGAME.");
  GUIElement* startButton = new GUIButton(sf::Vector2f(window->getView().getCenter().x, window->getView().getCenter().y), sf::Vector2f(270, 100), "START");
  GUIElement* optionsButton = new GUIButton(sf::Vector2f(window->getView().getCenter().x, window->getView().getCenter().y + 120), sf::Vector2f(270, 100), "QUIT");

  canvas.addElement(title);
  canvas.addElement(startButton);
  canvas.addElement(optionsButton);

  sf::Event* currEvent = new sf::Event();
  while (window->isOpen()) {
    window->clear(sf::Color::Black);
    canvas.update(currEvent, window);
    window->draw(canvas);
    window->display();
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