#ifndef LEVEL1_H
#define LEVEL1_H

#include "raylib.h"
#include "Item.h"

class Level1
{

private:
    Texture2D backgroundBorder{LoadTexture("resources/textures/background/border.png")};
    Texture2D background{LoadTexture("resources/textures/background/background1.png")};

    Texture2D disappearTexture{LoadTexture("resources/textures/items/collected.png")};
    Texture2D appleTexture{LoadTexture("resources/textures/items/apple.png")};
    Texture2D checkpointTexture{LoadTexture("resources/textures/items/checkpoint.png")};

    // TODO: check why lost animation
    Item apples[5];

    // TODO: same as apples, lost animation
    Item checkpoints[3]{Item(checkpointTexture, 10, {700.0f, 370.0f}, RAYWHITE, disappearTexture),
                        Item(checkpointTexture, 10, {200.0f, 88.0f}, RAYWHITE, disappearTexture),
                        Item(checkpointTexture, 10, {730.0f, 237.0f}, RAYWHITE, disappearTexture)};

public:
    Level1();
    void Init();
    void RenderBackground();
    void RenderItems();
    void Unload();
};

#endif