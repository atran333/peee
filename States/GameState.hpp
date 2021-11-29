#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#include "State.hpp"

class GameState: public State{
    public:
        GameState(sf::RenderWindow* window);
        virtual ~GameState();
        //Functions


        void updateKeybinds(const float& deltaTime);
        void update(const float& deltaTime);
        void endState();
        void render(sf::RenderTarget* target = nullptr);
    private:

};
#endif //