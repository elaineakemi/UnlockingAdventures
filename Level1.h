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

    // workaround to fix apples animation
    int applesCount = 5;
    Item apple1{appleTexture, 17, {75.0f, 250.0f}, RAYWHITE, disappearTexture};
    Item apple2{appleTexture, 17, {100.0f, 280.0f}, RAYWHITE, disappearTexture};
    Item apple3{appleTexture, 17, {125.0f, 250.0f}, RAYWHITE, disappearTexture};
    Item apple4{appleTexture, 17, {150.0f, 280.0f}, RAYWHITE, disappearTexture};
    Item apple5{appleTexture, 17, {175.0f, 250.0f}, RAYWHITE, disappearTexture};
    Item *apples[5]{&apple1, &apple2, &apple3, &apple4, &apple5};

    // workaround to fix checkpoints animation
    Item checkpoint1{checkpointTexture, 10, {700.0f, 370.0f}, RAYWHITE, disappearTexture};
    Item checkpoint2{checkpointTexture, 10, {200.0f, 88.0f}, RAYWHITE, disappearTexture};
    Item checkpoint3{checkpointTexture, 10, {730.0f, 237.0f}, RAYWHITE, disappearTexture};
    Item *checkpoints[3]{&checkpoint1, &checkpoint2, &checkpoint3};

public:
    Level1();
    void Init();
    void RenderBackground();
    void RenderItems();
    void Update();
    void Unload();
};

#endif