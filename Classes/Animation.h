//
// Created by bcj11 on 2/3/2022.
//

#ifndef AIR_ATTACK_ANIMATION_H
#define AIR_ATTACK_ANIMATION_H

#include <vector>
#include <SFML/Graphics.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////
/// @Class_Name: Animation
/// @Programmer: Fam Trinli, documented and implemented by BRadley Johnson
/// @Description: This class is used to handle the graphics for each entity in the game. Whether
///               an entity will have an animation or not. An animation object contains a
///               sprite (with a texture) that will be drawn at the position of an Entity object.
///               If desired, the texture can cycle through frames of animation using the update() function
///               which changes the sprite's TextureRect.
/// @Public_Member_Variables:
///     @Frame: <float> Used to store what frame the animation is currently on, casted to int when used for indexing
///             the frames vector. Set to 0 for the first frame
///     @Speed: <float> Used to determine the rate at which frames change in update()
///     @Sprite: <SFML::Sprite> Sprite object to be drawn at the location of an Entity object
///     @frames: <std::vector<IntRect>> This data structure contains a vector of IntRect objects.
///              Each rect holds an x,y,width,and height. These values are used to change which
///              portion of the Sprite object's texture is going to be rendered using
///              sprite.setTextureRect(<param>) For more on IntRect,
///              see https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Rect.php
///
/////////////////////////////////////////////////////////////////////////////////////////////
    class Animation {
    public:
        float Frame, speed; //Frame holds the value of the current frame, speed is the rate at which frames are changed
        bool flash;
        int flashCount;
        sf::Sprite sprite;
        std::vector<sf::IntRect> frames; //Contains vector of IntRects for frames. See class heading documentation for detailed description.

        void update();
        bool isEnd() const;


        explicit Animation() = default; //Only exists to create un-initialized Animation objects

        /*****************************************************************
         * @Name: Animation Constructor
         * @Programmer: Fam Trinli
         * @Description: Constructor for the Animation class, it initializes
         *               the sprite member object with the right texture, as
         *               well as establishes the vector of rects so that the sprite
         *               can quickly change its TextureRect.
         * @param texture: SFML::Texture obj passed by reference, used as the texture for the sprite
         * @param xOffset: The starting x position on the texture for SetTextureRect. The loop will move right from here
         * @param yOffset: The starting y position on the texture for the SetTextureRect, is not changed in the loop
         * @param width: Establishes the width of each frame
         * @param height: Establishes the height of each frame
         * @param frameCount: The number of frames that need to be "harvested" from the texture
         * @param Speed: The speed at which the animation will play, 0 for a still texture
         *******************************************************************/
        Animation(sf::Texture &texture, int xOffset, int yOffset, int width, int height, int frameCount, float Speed) {
            Frame = 0;
            speed = Speed;
            flash = false;
            flashCount = 0;
            //Move across the image and find the coordinates of the rects to add to frames
            for (int i = 0; i < frameCount; i++) {
                frames.emplace_back(xOffset + i * width, yOffset, width, height);
            }

            sprite.setTexture(texture);                  //Establish that the sprite uses the texture
            sprite.setOrigin(width / 2, height / 2);   //Make sure the texture origin is at the center of the texture
            sprite.setTextureRect(frames[0]);  //Make sure the Sprite's TextureRect is set to frame 0, (i,e,the first frame)
        }


    };



#endif //AIR_ATTACK_ANIMATION_H
