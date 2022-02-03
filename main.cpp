#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
#include <list>
#include <cmath>
#include <SFML/Audio.hpp>
#include "Classes/Animation.h"
#include "Classes/Entity.h"

#include <iostream>

using namespace sf;

const int Width = 1200;
const int Height = 800;

//Constant value of pi/180 to convert from degrees to radians
const float DegreesToRadians = 0.017453f;


int main() {
    //'app' is the main window of the game
    RenderWindow AirAttack(VideoMode(800, 600), "Car Racing Game!");
    AirAttack.setFramerateLimit(60);      //Limit the refresh rate to no more than 60 fps

    //Loading images for racing game with catch for loading failure
    Texture chopperT, chopperGreenT;
    if (!chopperT.loadFromFile("images/chopper.png")) { return EXIT_FAILURE;}
    if (!chopperGreenT.loadFromFile("images/chopperGreen.png")) {return EXIT_FAILURE;}

    chopperT.setSmooth(true); //Smooths the image when displayed on the screen
    chopperGreenT.setSmooth(true);

    //Create Craft Sprite object: sCraft
    Sprite sCraft(chopperT);

    sCraft.setOrigin(129.5,51.5); //Sets these coordinates on the texture to the center of the sprite.

    Entity Craft;
    std::cout << "Running. . . " << std::endl;


    //Main Loop
    while (AirAttack.isOpen()) {
        Event event{};
        while (AirAttack.pollEvent(event)) {
            if (event.type == Event::Closed) {
                AirAttack.close();
            }
        }

        //Initialize variables
        float speed = 0, angle = 0;
        float maxSpeed = 12.0;
        float acc = 15, dec = 0.4;
        float turnSpeed = 0.08;

        //16 bits, can go up to about 65,000. It is only used to change scenes so doesn't need to be big or negative
        /* scene 0 = quit
         * scene 1 = main menu
         * scene 2 = classic level
         **/
        unsigned short int scene = 1;



        ///Menu Loop///
        while (scene == 1) {
            scene = 2;
        }



        while (scene == 2) {
            speed = 0;
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (speed < 0) {
                    speed -= dec;
                }
                else {
                    speed += acc;
                }
            }


            //#TODO create derrived class for craft
            //Craft.setSpeed(speed);
            //Craft.move();




            ///BEGINNING OF DRAWING SECTION OF GAME LOOP
            AirAttack.clear(Color::White); //Clears the canvas

            //Order of Drawing matters, do background elements first:

            //Refresh the position of the craft sprite: 'sCraft' from the craft object: 'Craft'.
            // It needs to know where to draw them next and at what rotation
            //sCraft.setPosition(Craft.getX(), Craft.getY());
            //sCraft.setRotation(Craft.getAngle() * 180 / 3.141593);
            //Finally Draw the craft on the next frame
            //AirAttack.draw(sCraft);
            //After Drawing everything, display the canvas
            AirAttack.display();



            //Close mid-game
            while (AirAttack.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    scene = 0;
                    AirAttack.close();
                }
            }

        }
    }
    return 0;
}
