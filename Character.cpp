#include "Character.h"

const int FRAME_SPEED = 8;

Character::Character(Texture2D txtr, int numFrames, Vector2 pos, Color c)
    : texture(txtr),
      numberFrames(numFrames),
      position(pos),
      color(c),
      frameRec({0.0f, 0.0f, (float)texture.width / numberFrames - 1, (float)texture.height}),
      currentFrame(0),
      framesCounter(0),
      framesSpeed(FRAME_SPEED) {}

void Character::Render()
{
    DrawTextureRec(texture, frameRec, position, color);

    framesCounter++;
    if (framesCounter >= (60 / framesSpeed))
    {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > numberFrames - 1)
            currentFrame = 0;

        frameRec.x = (float)currentFrame * (float)texture.width / numberFrames;
    }
}

void Character::Move(Vector2 offset)
{
    position.x += offset.x;
    position.y += offset.y;
}

Vector2 Character::GetPosition() const
{
    return position;
}

Rectangle Character::GetPositionRec() const
{
    return {position.x, position.y, (float)texture.width / numberFrames - 1, (float)texture.height};
}