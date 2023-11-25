#include "Level1.h"

Level1::Level1() {}

void Level1::Init()
{

    Item apple1(appleTexture, 17, {75.0f, 250.0f}, RAYWHITE, disappearTexture);
    Item apple2(appleTexture, 17, {100.0f, 280.0f}, RAYWHITE, disappearTexture);
    Item apple3(appleTexture, 17, {125.0f, 250.0f}, RAYWHITE, disappearTexture);
    Item apple4(appleTexture, 17, {150.0f, 280.0f}, RAYWHITE, disappearTexture);
    Item apple5(appleTexture, 17, {175.0f, 250.0f}, RAYWHITE, disappearTexture);

    apples[0] = apple1;
    apples[1] = apple2;
    apples[2] = apple3;
    apples[3] = apple4;
    apples[4] = apple5;
}

void Level1::RenderBackground()
{
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(backgroundBorder, 0, 0, WHITE);
}

void Level1::RenderItems()
{
    for (auto apple : apples)
    {
        apple.Render();
    }

    for (Item item : checkpoints)
    {
        item.Render();
    }
}

void Level1::Unload()
{
    UnloadTexture(background);
    UnloadTexture(backgroundBorder);
    UnloadTexture(disappearTexture);
    UnloadTexture(appleTexture);
    UnloadTexture(checkpointTexture);
}