#ifndef MAINMENUSTATE_HPP
#define MAINMENUSTATE_HPP

#include "../States/GameState.hpp"

class MainMenuState: public State{
    public:
        //variables
        sf::RectangleShape background;

        MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
        virtual ~MainMenuState();
        //Functions

        void nextStage();
        void updateInput(const float& deltaTime);
        void update(const float& deltaTime);
        void endState();
        void render(sf::RenderTarget* target = nullptr);
    private:

};
#endif //