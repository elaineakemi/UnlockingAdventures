#include "Item.h"

Item::Item(Texture2D itemtx, int numFrames, Vector2 pos, Color c)
    : itemTexture(itemtx),
      numberFrames(numFrames),
      position(pos),
      color(c),
      frameRec({0.0f, 0.0f, (float)itemTexture.width / numberFrames - 1, (float)itemTexture.height}),
      currentFrame(0),
      framesCounter(0),
      framesSpeed(8), // TODO: add to some config file
      collectedTexture(LoadTexture("resources/textures/items/collected.png")),
      isCollected(false)
{
}

void Item::Draw()
{
    if (!isCollected)
    {
        DrawTextureRec(itemTexture, frameRec, position, color);

        framesCounter++;
        if (framesCounter >= (60 / framesSpeed))
        {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > numberFrames - 1)
                currentFrame = 0;

            frameRec.x = (float)currentFrame * (float)itemTexture.width / numberFrames;
        }
    }
}

Vector2 Item::GetPosition() const
{
    return position;
}

Rectangle Item::GetPositionRec() const
{
    return {position.x, position.y, (float)itemTexture.width / numberFrames - 1, (float)itemTexture.height};
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
