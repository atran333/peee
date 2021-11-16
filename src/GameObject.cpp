#include "GameObject.hpp"

GameObject::GameObject() :
texture(),
sprite(),
pos(sf::Vector2f(0.f, 0.f))
{}

GameObject::GameObject(sf::Texture tex, sf::Sprite spr) :
texture(tex),
sprite(spr)
{}

GameObject::GameObject(sf::Texture tex, sf::Sprite spr, std::string str) :
texture(tex),
sprite(spr),
tag(str)
{}

GameObject::GameObject(sf::Texture tex, sf::Sprite spr, sf::Vector2f pos) :
texture(tex),
sprite(spr),
pos(pos)
{}

GameObject::GameObject(sf::Texture tex, sf::Sprite spr, sf::Vector2f pos, std::string str)  :
texture(tex),
sprite(spr),
pos(pos),
tag(str)
{}

GameObject::~GameObject() {}

void GameObject::setSprite(sf::Sprite spr) { sprite = spr; }
void GameObject::setTexture(sf::Texture tex) { texture = tex; }
void GameObject::setPos(sf::Vector2f vec) { pos = vec; }
void GameObject::setName(std::string str) { tag = str; }

sf::Texture GameObject::getTexture() { return texture; }
sf::Sprite GameObject::getSprite() { return sprite; }
sf::Vector2f GameObject::getPos() { return pos; }
std::string GameObject::getName() { return tag; }