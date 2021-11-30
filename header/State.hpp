#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <vector>


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector> 

class State
{
    protected:
        sf::RenderWindow* window;
        std::stack<State*>* states;
        std::vector<sf::Texture*> textures;
        bool quit;
    public:
        //saves sending it in all the time
        
        State(sf::RenderWindow* window, std::stack<State*>* states);
        virtual ~State();
        const bool& getQuit() const;
        virtual void endState() = 0;
        virtual void checkForQuit();
        virtual void updateInput(const float& deltaTime);
        virtual void update(const float& deltaTime) = 0;
        // if nothing is given in the parameters, we'll run into the window, if u want to send a specific target, send in the parameter
        virtual void render(sf::RenderTarget* target = nullptr) = 0;
};
#endif //
