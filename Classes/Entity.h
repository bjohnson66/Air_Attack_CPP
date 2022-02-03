//
// Created by bcj11 on 2/3/2022.
//

#ifndef AIR_ATTACK_ENTITY_H
#define AIR_ATTACK_ENTITY_H

#include <SFML/Graphics.hpp>
#include "Animation.h"

/////////////////////////////////////////////////////////////////////////////////////////////
/// @Class_Name: Entity
/// @Programmer: Fam Trinli
/// @Description: This class is a base class used for all entities in the game.
/// @Public_Member_Variables:
///     @animation Animation object that will be drawn at the x,y,position of the Entity
///     @X: <float>X position of the Entity
///     @Y: <float>Y Position of the Entity
///     @dx: <float> x component of the entity's velocity
///     @dy: <float> y component of the entity's velocity
///     @Angle: <float>Rotation of the Entity in degrees
///     @radius: <float>Radius of the Entity's collider circle
///     @life: <bool> Is the entity alive
///     @name: <std::string> name of the object
///
/////////////////////////////////////////////////////////////////////////////////////////////
class Entity {
public:
    float x, y, dx, dy, R, angle;
    bool life;
    bool fire;
    int hits;
    int bulletType;
    std::string name;
    Animation anim;

//Explicit constructor that sets the entity to be alive. All other parameters are set with settings.
    explicit Entity() {
        life = true;
        fire = false;
        hits = 0;
        bulletType = 0;
    }

    void settings(Animation const &animation, int const &X, int const &Y, float const &Angle, int const &radius);

//Virtual function that will be overridden by derived classes
    virtual void update() {};

    void draw(sf::RenderWindow &app);

//Virtual function that will be overridden by derived classes
    virtual ~Entity() = default;
};


#endif //AIR_ATTACK_ENTITY_H
