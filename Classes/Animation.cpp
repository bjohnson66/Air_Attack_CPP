//
// Created by bcj11 on 2/3/2022.
//

#include "Animation.h"


using namespace sf;

/***************************************************************************
 * @Name: update()
 * @Programmer: Fam Trinli
 * @Description: Cycles the Sprite's TextureRect to that of the next frame.
 *               This function cycles to the next frame by "Speed" frames to the
 *               casted integer value of Frame + speed
 *******************************************************************************/
void Animation::update() {
    Frame += speed;
    int n = static_cast<int>(frames.size());
    if (Frame >= static_cast<float>(n)) { Frame -= static_cast<float>(n); }
    if (n > 0) { sprite.setTextureRect(frames[int(Frame)]); }
    if (flash && (flashCount <= 65)){
        if (flashCount%4 == 0) {
            sprite.setColor({0, 0, 0});
        }else{
            sprite.setColor({255,255,255});
        }

        flashCount++;
    }else{
        flash = false;
        flashCount = 0;
    }
}


/***************************************************************************
 * @Name: isEnd()
 * @Programmer: Fam Trinli
 * @Description: Returns true if adding speed to Frame will result in an
 *               attempt to index outside of the range of frames. Returns True
 *               if we are at the end of the frames vector
 *
 ************************************************************************/
bool Animation::isEnd() const {
    return Frame + speed >= static_cast<float>(frames.size());
}


