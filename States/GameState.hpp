#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../header/State.hpp"

class GameState: public State{
    public:
        sf::RectangleShape background;
        GameState(sf::RenderWindow* window, std::stack<State*>* states);
        virtual ~GameState();
        //Functions


        void updateInput(const float& deltaTime);
        void update(const float& deltaTime);
        void endState();
        void render(sf::RenderTarget* target = nullptr);
    private:

};
#endif //