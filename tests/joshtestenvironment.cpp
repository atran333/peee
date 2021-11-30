#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include "../header/GameObject.hpp"
using namespace std;


#define DEBUG 1

#if DEBUG
  #define LOG(x) (cout << x << endl)
#else
  #define LOG(x) 
#endif

class AudioTest : public GameComponent {
  private:
    sf::Sound bruhMoment;
    sf::SoundBuffer bruhBuffer;
  public:
    virtual void updateGameComponent() {
      bruhMoment.play();
      cout << "here" << endl;
    }
    virtual void start() {
      // note: set a parameter here, don't hard code
      bruhBuffer.loadFromFile("tempassets/baby_cry.wav");
      bruhMoment.setBuffer(bruhBuffer);
    }
};

class MovementTest : public GameComponent {
  private:
    sf::Vector2f position;
  public:
    virtual void updateGameComponent() {
      
    }
    virtual void start() {
      
    }
    
};

class GraphicsTest : public GameComponent {
  private:
    sf::Texture texture;
    sf::Sprite sprite;
  public:
    virtual void updateGameComponent() {
      
    }
};

int main()
{
  sf::RenderWindow window(sf::VideoMode(1980, 1080), "SFML window", sf::Style::Fullscreen);
  sf::Texture texture;
  texture.loadFromFile("tempassets/bossbaby.jpg");
  sf::Sprite sprite(texture);
  sf::Event event; 
  AudioTest* bruhTest = new AudioTest;
  GameObject gme(texture, sprite, sf::Vector2f(0.0f, 0.0f), "");
  gme.addComponent(bruhTest);
  bruhTest->start();
  while (window.isOpen()) {
    while(window.pollEvent(event)) {
      if (event.type == sf::Event::KeyPressed) {
        switch(event.key.code) {
        case(sf::Keyboard::Escape):
          window.close();
          break;
        case(sf::Keyboard::Q):
          gme.getComponent(0)->updateGameComponent();
          break;
        default:
          window.draw(gme.getSprite());
          window.display();
          window.clear();
        }
    }
  }
    
}
  return 0;
}