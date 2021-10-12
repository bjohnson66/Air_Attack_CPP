#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include "Craft.h"

#include <iostream>

using namespace sf;


int main() {
    //'app' is the main window of the game
    RenderWindow AirAttack(VideoMode(800, 600), "Car Racing Game!");
    AirAttack.setFramerateLimit(60);      //Limit the refresh rate to no more than 60 fps

    //Loading images for racing game with catch for loading failure
    Texture chopperT, chopperGreenT;
    if (!chopperT.loadFromFile("images/chopper.png")) {return EXIT_FAILURE;}
    if (!chopperGreenT.loadFromFile("images/chopperGreen.png")) {return EXIT_FAILURE;}
    chopperT.setSmooth(true); //Smooths the image when displayed on the screen
    chopperGreenT.setSmooth(true);

    //Create Craft Sprite object: sCraft
    Sprite sCraft(chopperT);

    sCraft.setOrigin(129.5,51.5); //Sets these coordinates on the texture to the center of the sprite.

    craft Craft;

    std::cout << "Running. . . " << std::endl;

    //Main Loop
    while (AirAttack.isOpen()) {
        Event e;
        while (AirAttack.pollEvent(e)) {
            if (e.type == Event::Closed) {
                AirAttack.close();
            }

        }

        float speed = 0, angle = 0;
        float maxSpeed = 12.0;
        float acc = 15, dec = 0.4;
        float turnSpeed = 0.08;

        //Check for when the Arrow Keys are Pressed: Up
        bool Up = false, Right = false, Down = false, Left = false;
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            Up = true;
        }

        if (Up && speed < maxSpeed) {
            if (speed < 0){
                speed -= dec;
            } else {
                speed += acc;
            }
        }


        Craft.setSpeed(speed);

        Craft.move();




        ///BEGINNING OF DRAWING SECTION OF GAME LOOP
        AirAttack.clear(Color::White); //Clears the canvas

        //Order of Drawing matters, do background elements first:

        //Refresh the position of the craft sprite: 'sCraft' from the craft object: 'Craft'.
        // It needs to know where to draw them next and at what rotation
        sCraft.setPosition(Craft.getX(), Craft.getY());
        sCraft.setRotation(Craft.getAngle() * 180/3.141593);

        //Finally Draw the craft on the next frame
        AirAttack.draw(sCraft);

        //After Drawing everything, display the canvas
        AirAttack.display();

    }
    return 0;
}
