#include "Character.h"

Character::Character(Texture2D txtr, int numFrames, Vector2 pos, Texture2D disappearChar)
    : texture(txtr),
      numberFrames(numFrames),
      position(pos),
      frameRec({0.0f, 0.0f, (float)texture.width / numberFrames - 1, (float)texture.height}),
      currentFrame(0),
      framesCounter(0),
      disappearTexture(disappearChar)
{
}

Character::Character() {}

void Character::Render()
{
    // If character died and already rendered the disappear texture, do nothing
    if (renderDied == 0)
        return;

    if (GetIsAlive())
    {
        // Update frameRec to flip/unflip the texture
        if (isFlipTexture && frameRec.width > 0)
        {
            frameRec.width = -frameRec.width;
        }
        else if (!isFlipTexture && frameRec.width < 0)
        {
            frameRec.width = -frameRec.width;
        }
        DrawTextureRec(texture, frameRec, position, defaultColour);
    }
    else
    {
        int frames = 1;
        if (isDisappearAfterCollect)
        {
            renderDied--;
            frames = 5; // Default disappear texture frames
        }
        Rectangle rect = {0.0f, 0.0f, (float)disappearTexture.width / frames, (float)disappearTexture.height};
        DrawTextureRec(disappearTexture, rect, position, defaultColour);
    }

    // Change between frames in the texture to "animate"
    // Reference https://keasigmadelta.com/blog/raylib-2d-challenge-part-2-jumping-and-sound-effects/
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

// Set back is alive and default render for disappear texture
void Character::Restart()
{
    renderDied = 5;
    isAlive = true;
}

// Return the base position rectangle
Rectangle Character::GetPositionRec() const
{
    return {position.x, position.y, (float)texture.width / numberFrames - 1, (float)texture.height};
}