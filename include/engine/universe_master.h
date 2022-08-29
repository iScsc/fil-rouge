#ifndef ENGINE_UNIVERSE_MASTER_H
#define ENGINE_UNIVERSE_MASTER_H

#include <iostream>
#include <list>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics.hpp>

#include "engine/entity.h"
#include "engine/physic/physic.h"
#include "engine/physic/phxbox.h"

typedef std::list<Entity*> EntityStack;

typedef	std::list<Physic*> PhysicStack;

typedef std::list<sf::Drawable*> SpriteStack; 

typedef std::list<Box<PhxBox>*> PhxBoxStack;
class UniverseMaster
{
private:
    EntityStack allEntity;
    PhysicStack allPhysic;
    SpriteStack allSprite;
    PhxBoxStack allPhxBox;

    void updatePhysic();
    void updateEntity();
    void updateSprite();
    
    std::list<Collision<PhxBox>> checkPhxCollision();

    sf::RenderWindow* window;

public:
    UniverseMaster(/* args */) = default;

    void linkWindow(sf::RenderWindow* p_window){this->window = p_window;};

    void addEntity(Entity* entity);

    void update();
};




#endif
