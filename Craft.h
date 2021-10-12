//
// Created by bcj11 on 10/12/2021.
//

#ifndef Air_Attack_CRAFT_H
#define Air_Attack_CRAFT_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>
#include <vector>

using namespace sf;

class craft {
public:
    explicit craft(float const &X_Position = 100, float const &Y_Position = 100, float const &Speed = 5, float const &Angle = 0){
        setX(X_Position);
        setY(Y_Position);
        setSpeed(Speed);
        setAngle(Angle);
    }

    //Getters and Setters
    float getX() const{ return(this->x);}
    float getY() const{ return(this->y);}
    float getSpeed() const{ return(this->speed);}
    float getAngle() const{ return(this-> angle);}

    void setX(float const &X_Position) { this->x = X_Position;}
    void setY(float const &Y_Position) { this->y = Y_Position;}
    void setSpeed(float const &Speed) { this->speed = Speed;}
    void setAngle(float const &Angle) { this->angle = Angle;}

    void move(){
        this -> y -= speed;
        if (this -> y < 600) {
            this->y += 5; //gravity
        }
    }

private:
    float x, y, speed, angle;
};

#endif //Air_Attack_CRAFT_H
