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
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
  while (window.isOpen()) {
    window.display();
  }
  return 0;
}