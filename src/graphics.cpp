#include <SFML/Graphics.hpp>
#include <Sprite.hpp>
#include "graphics.hpp"
#include <iostream>

Texture getTexture()
{
    return texture;
}

Texture setTexture()
{
    sf::Texture texture;
    sf::Sprite sprite(texture);
    //load texture
    texture.loadFromFile("texture.png");
}

