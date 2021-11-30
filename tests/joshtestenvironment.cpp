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
    }
    virtual void start() {
      // note: set a parameter here, don't hard code
      bruhBuffer.loadFromFile("tempassets/baby_cry.wav");
      bruhMoment.setBuffer(bruhBuffer);
    }
};

class MovementTest : public GameComponent {
  private:
    float speed;
  public:
    GameObject* circularReference;
    sf::Event* eventPtr; 
    MovementTest(GameObject* obj, sf::Event* event) : circularReference(obj), eventPtr(event) {}
    virtual void updateGameComponent() {
        sf::Vector2f left(-10.0f, 0.0f);
        sf::Vector2f right(10.0f, 0.0f);
        sf::Vector2f up(0.0f, 10.0f);
        sf::Vector2f down(0.0f, -10.0f);
        if (eventPtr->type == sf::Event::KeyPressed) {
          if (eventPtr->key.code == sf::Keyboard::S)
          {
            circularReference->getPosMutator()->y += up.y;
            circularReference->getSpriteMutator()->move(up);
          }
          else if (eventPtr->key.code == sf::Keyboard::W)
          {
            circularReference->getPosMutator()->y += down.y;
            circularReference->getSpriteMutator()->move(down); 
          }
          else if (eventPtr->key.code == sf::Keyboard::D)
          {
            circularReference->getPosMutator()->x += right.x;
            circularReference->getSpriteMutator()->move(right); 
          }
          else if (eventPtr->key.code == sf::Keyboard::A)
          {
            circularReference->getPosMutator()->x += left.x;
            circularReference->getSpriteMutator()->move(left);
          }
        }
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
  sf::RenderWindow window(sf::VideoMode(1980, 1080), "SFML window");
  sf::Texture texture;
  texture.loadFromFile("tempassets/bossbaby.jpg");
  sf::Sprite sprite(texture);
  sf::Event event; 
  AudioTest* bruhTest = new AudioTest;
  GameObject gme(texture, sprite, sf::Vector2f(1.0f, 1.0f), "");
  MovementTest* moveTest = new MovementTest(&gme, &event);
  gme.addComponent(bruhTest);
  gme.addComponent(moveTest);
  bruhTest->start();
  
  while (window.isOpen()) {
    while(window.pollEvent(event)) {
    gme.getComponent(1)->updateGameComponent();
      if (event.type == sf::Event::KeyPressed) {
        gme.getComponent(0)->updateGameComponent();
        switch(event.key.code) {
        case(sf::Keyboard::Escape): {
          window.close();
          break;
        }
        default: {
          window.draw(gme.getSprite());
          window.display();
          window.clear();
        }
      }
    }
  }
}
  return 0;
}