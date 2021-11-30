#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <iostream>
using namespace std;

int updateGameComponent()
{
    sf::RenderWindow window(sf::VideoMode(600,600), "function");
    sf::SoundBuffer buffer;
    //call setSound to retrieve desired audio file
    if (!buffer.loadFromFile("HURRICANE.mp3"))
    {
        cout << "ERROR" << endl;
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        window.clear();
        window.display();
    }
}
