#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <fstream>
#include <sstream>
using namespace std;

class movement : public GameComponent
{
    private:
    //point to game object I'm associating with
    GameObject* mvmt;
    

    public:
    virtual void updateGameComponent()
    {
        while (window2.isOpen())
        {
        sf::Event event;
        while (window2.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window2.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::Escape : window2.close(); break;
                    case sf::Keyboard::Up :     upFlag=true; break;
                    case sf::Keyboard::Down:    downFlag=true; break;
                    case sf::Keyboard::Left:    leftFlag=true; break;
                    case sf::Keyboard::Right:   rightFlag=true; break;
                    default : break;
                }
            }
            if (event.type == sf::Event::KeyReleased)
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::Up: upFlag=false; break;
                    case sf::Keyboard::Down: downFlag=false; break;
                    case sf::Keyboard::Left: leftFlag=false; break;
                    case sf::Keyboard::Right: rightFlag=false; break;
                    default : break;
                }
            }
        }
    //speed of sprite
        #define SPEED 20
        if (leftFlag == true)
        {
            x = x - SPEED;
        }
        if (rightFlag == true)
        {
            x = x + SPEED;
        }
        if (upFlag == true)
        {
            y = y - SPEED;
        }
        if (downFlag == true)
        {
            y = y - SPEED;
        }
//boundaries
        if (x < 0)
        {
            x = 0;
        }
        if (x > (int)window2.getSize().x) 
        {
            x = window2.getSize().x;
        }
        if (y < 0)
        {
            y = 0;
        }
        if (y > window2.getSize().y)
        {
            y = window2.getSize().y;
        }

//clear, draw, set background
        window2.clear( sf::Color(120,120,120));
        sprite.setPosition(x,y);
        window2.clear();
        window2.draw(sprite);
        window2.display();
    }
    return 0;
    }
    virtual void start()
    {
        sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
        sf::RenderWindow window2(sf::VideoMode(desktopMode.width, desktopMode.height, desktopMode.bitsPerPixel),"sprite moving", sf::Style::Fullscreen);

        window2.setVerticalSyncEnabled (true);
        window2.setKeyRepeatEnabled(false);


        sf::Texture texture2;
        texture2.loadFromFile("me.png");

        sf::Sprite sprite;
        sprite.setTexture(texture2);
        
        sf::FloatRect spriteSpace = sprite.getGlobalBounds();
        //center
        sprite.setOrigin(spriteSpace.width/2.,spriteSpace.height/2.);
        
        int x = window2.getSize().x/2;
        int y = window2.getSize().y/2;

        bool upFlag = false;
        bool downFlag = false;
        bool leftFlag = false;
        bool rightFlag = false;
    }




}


