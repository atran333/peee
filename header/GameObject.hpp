#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "GameComponent.hpp"
#include <vector>

class GameObject {
    private:
        std::vector<GameComponent*> components;
    protected:
        std::string tag = "";
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Vector2f pos;
    public:
        GameObject();
        GameObject(sf::Texture, sf::Sprite);
        GameObject(sf::Texture, sf::Sprite, std::string);
        GameObject(sf::Texture, sf::Sprite, sf::Vector2f);
        GameObject(sf::Texture, sf::Sprite, sf::Vector2f, std::string);
        ~GameObject();
        void setSprite(sf::Sprite);
        void setTexture(sf::Texture);
        void setPos(sf::Vector2f);
        void setName(std::string);
        void addComponent(GameComponent*); 
        void removeComponent(int i); 
        GameComponent* getComponent(int i); 
        sf::Texture getTexture();
        sf::Sprite getSprite();
        sf::Vector2f getPos();
        std::string getName();
};

#endif /*GAMEOBJECT_HPP*/
