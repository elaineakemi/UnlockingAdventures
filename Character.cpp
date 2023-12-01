#include "Character.h"

Character::Character(TextureFrames txtr, Vector2 pos)
    : textureWithFramesNumber(txtr),
      killTextureFrames(txtr),
      position(pos),
      frameRec({0.0f, 0.0f, (float)textureWithFramesNumber.texture.width / textureWithFramesNumber.frames - 1, (float)textureWithFramesNumber.texture.height}),
      currentFrame(0),
      framesCounter(0) {}

Character::Character(TextureFrames txtr, Vector2 pos, TextureFrames killTexture)
    : textureWithFramesNumber(txtr),
      killTextureFrames(killTexture),
      position(pos),
      frameRec({0.0f, 0.0f, (float)textureWithFramesNumber.texture.width / textureWithFramesNumber.frames - 1, (float)textureWithFramesNumber.texture.height}),
      currentFrame(0),
      framesCounter(0) {}

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
        DrawTextureRec(textureWithFramesNumber.texture, frameRec, position, defaultColour);
    }
    else
    {
        if (isDisappearAfterCollect)
        {
            renderDied--;
        }
        Rectangle rect = {0.0f, 0.0f, (float)killTextureFrames.texture.width / killTextureFrames.frames, (float)killTextureFrames.texture.height};
        DrawTextureRec(killTextureFrames.texture, rect, position, defaultColour);
    }

    // Change between frames in the texture to "animate"
    // Reference https://keasigmadelta.com/blog/raylib-2d-challenge-part-2-jumping-and-sound-effects/
    framesCounter++;
    if (framesCounter >= (60 / 8))
    {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > textureWithFramesNumber.frames - 1)
            currentFrame = 0;

        frameRec.x = (float)currentFrame * (float)textureWithFramesNumber.texture.width / textureWithFramesNumber.frames;
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
    return {position.x, position.y, (float)textureWithFramesNumber.texture.width / textureWithFramesNumber.frames - 1, (float)textureWithFramesNumber.texture.height};
}

Vector2 Character::GetPosition() const
{
    return position;
}