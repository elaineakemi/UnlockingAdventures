#include "Scenario.h"

Scenario::Scenario(Texture2D txtr, int numFrames, Vector2 pos)
    : texture(txtr),
      numberFrames(numFrames),
      position(pos),
      frameRec({0.0f, 0.0f, (float)texture.width / numberFrames - 1, (float)texture.height}),
      currentFrame(0),
      framesCounter(0) {}

void Scenario::Render()
{
    DrawTextureRec(texture, frameRec, position, defaultColour);

    // Change between frames in the texture to "animate"
    framesCounter++;
    if (framesCounter >= (60 / 8))
    {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > numberFrames - 1)
            currentFrame = 0;

        frameRec.x = (float)currentFrame * (float)texture.width / numberFrames;
    }
}

Vector2 Scenario::GetPosition() const
{
    return position;
}

Rectangle Scenario::GetPositionRec() const
{
    return {position.x, position.y, (float)texture.width / numberFrames - 1, (float)texture.height};
}