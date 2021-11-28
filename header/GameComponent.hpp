#ifndef GAMECOMPONENT_HPP
#define GAMECOMPONENT_HPP

template<typename T>
class GameComponent {
    private:
        T gameComponent;
    public:
        GameComponent(T gameComponent) : gameComponent(gameComponent) {}
        virtual T getGameComponent() = 0; 
        virtual void setGameComponent(T gameComponent) = 0;
};

#endif