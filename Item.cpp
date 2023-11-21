#include "Item.h"

Item::Item(Texture2D txtr, int numFrames, Vector2 pos, Color c)
    : Character(txtr, numFrames, pos, c),
      collectedTexture(LoadTexture("resources/textures/items/collected.png")),
      isCollected(false)
{
}

void Item::Render()
{
    if (!isCollected)
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
}

void Item::Collect()
{

    if (!isCollected)
    {
        Rectangle rect = {0.0f, 0.0f, (float)collectedTexture.width / 5, (float)collectedTexture.height};
        DrawTextureRec(collectedTexture, rect, position, color);
        isCollected = true;
    }
}
