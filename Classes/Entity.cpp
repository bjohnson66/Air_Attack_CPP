//
// Created by bcj11 on 2/3/2022.
//

#include "Entity.h"

/***********************************************************************
 * @Name: settings
 * @Programmer: Fam Trinli
 * @Descriptoin: Functions as a multi-arg setter for each entity object.
 *               It sets the values of the entity's animation,x,
 *               y,(optional) angle, and (optional) radius. Does not contain any
 *               error checking.
 * @param animation Animation object that will be drawn at the x,y,position of the Entity
 * @param X: X position of the Entity
 * @param Y: Y Position of the Entity
 * @param Angle: Rotation of the Entity
 * @param radius: Radius of the Entity's collider circle
 *****************************************************************************/
void Entity::settings(Animation const &animation, int const &X, int const &Y, float const &Angle = 0, int const &radius = 1) {
    anim = animation;
    x = X;
    y = Y;
    angle = Angle;
    R = static_cast<float>(radius);
}

void Entity::draw(sf::RenderWindow &app) {
    anim.sprite.setPosition(x, y);
    anim.sprite.setRotation(angle + 90);
    app.draw(anim.sprite);

    ///Collider circle visual representation
    /*
    CircleShape circle(R);
    circle.setFillColor(Color(255,0,0,170));
    circle.setPosition(x,y);
    circle.setOrigin(R,R);
    app.draw(circle);
    //*/
}