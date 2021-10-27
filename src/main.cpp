#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

#define DEBUG 1

#if DEBUG
  #define LOG(x) (cout << x << endl)
#else
  #define LOG(x) 
#endif


int main() {
  LOG("hello world.");
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
  sf::Texture texture;
  texture.loadFromFile("me.png");
  sf::Sprite sprite(texture);
  while (window.isOpen()) {
    window.draw(sprite);
    window.display();
  }
  return 0;
}