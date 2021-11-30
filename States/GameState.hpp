#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../header/GameObject.hpp"
#include "../header/State.hpp"

class GameState: public State{
    public:
        sf::RectangleShape background;
        GameState(sf::RenderWindow* window, std::stack<State*>* states);
        virtual ~GameState();
        //Functions
        void updateInput(const float& deltaTime);
        void update(const float& deltaTime, sf::Event* event, sf::RenderWindow* window);
        void endState();
        void render(sf::RenderTarget* target = nullptr);
    private:
        /* USER DEFINED VARIABLES */
        GameObject* gme;
        sf::Sprite* sprite;
        sf::Texture* texture;
};
#endif //