#ifndef GAMECOMPONENT_HPP
#define GAMECOMPONENT_HPP

class GameComponent {
    public:
        // update function that allows a game component to be changed at runtime
        // doesn't need to be implemented, could just do empty declaration.
        // no other functions needed, logic and implementation come from the derived classes, 
        // not from the GameComponent class. 
        virtual void updateGameComponent() = 0;
};

#endif