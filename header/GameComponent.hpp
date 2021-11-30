#ifndef GAMECOMPONENT_HPP
#define GAMECOMPONENT_HPP

class GameComponent {
    public:
        // do your setup and initialization here.
        virtual void start() = 0;
        // update function that allows a game component to be changed at runtime
        // doesn't need to be implemented, could just do empty declaration.
        // no other functions needed, logic and implementation come from the derived classes, 
        // not from the GameComponent class. 
        virtual void updateGameComponent() = 0;
};

#endif